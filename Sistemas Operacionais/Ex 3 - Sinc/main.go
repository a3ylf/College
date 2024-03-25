package main
/*
Os tempos dos produtores, consumidores e da limpeza do buffer estão fora de sincronia
para mostrar que isso não faz diferença

não entendi claramente se eu devo enviar a frase inteira palavra por palavra de uma vez e liberar o semáforo
ou enviar uma palavra e liberar o semáforo, porém trocar essa lógica é bem simples
*/
import (
	"crypto/rand"
	"fmt"
	"math/big"
	"sync"
	"time"
)

const (
	MAX      = 4 // A quantidade de produtores e consumidores (4 para cada nesse caso)
	wordSize = 4 // tamanho das palavras que serão geradas
)

var (
	mut          sync.Mutex         // semáforo
	finished     bool       = false // verdadeira se o programa não tiver mais nada a fazer
	producerDead [MAX]bool          // verdadeiro para cada produtor que terminou sua produção
)

/*
Decidi implementar uma lista encadeada para melhorar minhas habilidades em GO, cada
nó contém a palavra a ser lida (word), quantos ainda faltam ler (toRead), se um produtor X leu
esse nó (eachRead) e o ponteiro para o próximo nó (next)
*/
type Node struct {
	word     string
	toRead   int
	eachRead [MAX]bool
	next     *Node
}
type linkedList struct {
	head *Node
}

// declaro a lista globalmente
var list linkedList

// Insere sempre no final da lista encadeada
func (ll *linkedList) Insert(word string) {

	newNode := &Node{word: word, toRead: MAX, next: nil}
	/*toRead vem com o máximo de threads
	  e irá ser decrementado quando algum consumidor o lê*/
	if ll.head == nil {
		ll.head = newNode
	} else {
		current := ll.head
		for current.next != nil {
			current = current.next
		}
		current.next = newNode
	}
}

// Deleta um nó da lista com base na palavra, traversa ela até encontrar
func (ll *linkedList) Delete(word string) {
	if ll.head == nil {
		return
	}
	if ll.head.word == word {
		ll.head = ll.head.next
		return
	}
	prev := ll.head
	for prev.next != nil {
		if prev.next.word == word {
			prev.next = prev.next.next
			return
		}
		prev = prev.next
		//go possui coleta de lixo, não é preciso dar free no nó excluido
	}
}

// Função gera strings aleartorias (Peguei de um outro projeto meu)
func randomString(length int) string {
	const charset = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789"

	randomString := make([]byte, length)
	charsetLength := big.NewInt(int64(len(charset)))

	for i := 0; i < length; i++ {
		randomIndex, err := rand.Int(rand.Reader, charsetLength)
		if err != nil {
			panic(err)
		}
		randomString[i] = charset[randomIndex.Int64()]
	}

	return string(randomString)
}

func producer(id int) {
	var frase [4]string
	//gerando uma frase com 4 palavras geradas aleartoriamente

	for i := 0; i < 4; i++ {
		frase[i] = randomString(wordSize)
	}
	// para fins de debug eu dou print na frase inteira, porém isso não consta nos requisitos
	fmt.Println("frase: " + frase[0] + " " + frase[1] + " " + frase[2] + " " + frase[3])
  // Versão 1: Envia a frase inteira palavra por palavra e depois libera o semáforo
  // Dessa forma a frase fica na sequência correta, na versão 2 não, muito mais lenta que a versão 2
	mut.Lock()
  for _, word := range frase {
    list.Insert(word) 
    time.Sleep(time.Millisecond * 500) // espera meio segundo
  }
  mut.Unlock()
  /*versão 2: Enviando uma palavra por vez e abrindo o semáforo
  for _, word := range frase {
		//envia uma palvra por vez ao buffer e espera 1 segundo, semáforo cerca a inserção na lista
		mut.Lock()
		list.Insert(word)
		mut.Unlock()
		time.Sleep(time.Second) //espera 1 segundo
	}
*/
	// se chegou aqui, é porque terminou de enviar sua frase inteira, logo, este produtor
	// terminou sua função e morreu
	producerDead[id] = true
}

/*
separei a função de consumir em si para poder utilizar recursão.
O código checa se o nó já foi lido por esse consumidor X, caso não tenha sido lido
lê, caso contrário checa o próximo, se o nó for nulo retorna no começo
*/
func consume(node *Node, id int) {
	if node == nil {
		return
	}

	if node.eachRead[id] {
		consume(node.next, id)
	} else {
		node.eachRead[id] = true          // Esse nó já leu, logo vira verdadeiro
		node.toRead--                     // Decrementa quantos ainda faltam ler
		fmt.Printf(node.word+" p%d|", id) //printa a palavra mais o ID
		if node.toRead == 0 {
			fmt.Println() // Quebra a linha quando todos os consumidores leram a palavra X
		}
	}
}

/* 
  waitGroup nesse caso é utilizado para fazer a thread principal esperar os
  consumidores terminarem para poder finalizar o código
  
  enquanto a thread main não sinalizar que acabou, continua.const
  Se a lista encadeada não estiver vazia no momento, chama a função acima de consumir
  espera 200 milisegundos
*/
func consumer(id int, wg *sync.WaitGroup) {
	defer wg.Done()
	for !finished {
		if list.head != nil {
		  //semáforo ativa na hora de consumir
			mut.Lock()
			consume(list.head, id)
			mut.Unlock()
			time.Sleep(time.Millisecond * 200)
		}
	}
}
/*
Em go, uma função é concorrente quando se coloca o prefixo go antes de chamar ela,
no caso estou criando 4 produtores e 4 consumidores, esse numero pode ser facilmente
modificado ao alterar a variável global MAX
*/
func main() {

	var consumerGroup sync.WaitGroup // Declaro a lista de espera dos consumidores
	
	consumerGroup.Add(MAX)

	for i := 0; i < MAX; i++ {
		go producer(i)
	}

	for i := 0; i < MAX; i++ {
		go consumer(i, &consumerGroup)
	}
  

	for !finished {
	  // Acaba quando todos os produtores estiverem mortos e a lista estiver vazia
		if !producing() && list.head == nil {
			finished = true
			break
		} else {
		  //Lista de palavras que já foram lidas recebidas da função abaixo
			words_to_clean := findFinished()
			//se a lista de palavras não for nula, ativa o semáforo e retira da lista
			//cada um que já foi lido
			if len(words_to_clean) != 0 {
				mut.Lock()
				for _, word := range words_to_clean {
					list.Delete(word)

				}
				mut.Unlock()
			}
			time.Sleep(time.Second * 2) // espera 2 segundos
		}
	}
	//espera os consumidores terminarem para dar fim ao código
	consumerGroup.Wait()
}

// traversa a lista encadeada e procura todos os nós que não faltam consumidor a ler (toRead = 0)
// retorna uma lista com todas as palavras que já foram lidas por todos
func findFinished() (words []string) {
	node := list.head
	for node != nil {
		if node.toRead == 0 {
			words = append(words, node.word)
		}
		node = node.next
	}
	return words
}

// Se existir algum produtor que ainda está vivo, retorna verdadeiro, caso contrário falso
func producing() bool {
	for i := 0; i < MAX; i++ {
		if !producerDead[i] {
			return true
		}
	}
	return false
}
