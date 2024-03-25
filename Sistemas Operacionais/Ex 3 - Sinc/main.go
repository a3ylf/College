package main

import (
	"crypto/rand"
	"fmt"
	"math/big"
	"sync"
	"time"
)

const (
	MAX      = 4
	wordSize = 4
)

// Função gera strings aleartorias
var (
	buffer   []string
	mut      sync.Mutex
	finished bool = false
	producerDead [MAX]bool
)

type Node struct {
	word     string
	read     int
	eachRead [MAX]bool
	next     *Node
}
type linkedList struct {
	head *Node
}

var list linkedList

func (ll *linkedList) Insert(word string) {

	newNode := &Node{word: word, read: MAX, next: nil}
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
	}
}
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

func producer(id int ,wg *sync.WaitGroup) {
	defer wg.Done()
	var frase [4]string
	//gerando uma frase com 4 palavras geradas aleartoriamente

	for i := 0; i < 4; i++ {
		frase[i] = randomString(wordSize)
	}
	fmt.Println("frase: " + frase[0] + " " + frase[1] + " " + frase[2] + " " + frase[3])
	for _, word := range frase {
		//envia uma palvra por vez ao buffer e espera 1 segundo
		mut.Lock()
		list.Insert(word)
		mut.Unlock()
		time.Sleep(time.Second)
	}
	producerDead[id] = true
}

func consume(node *Node, id int) {
	if node == nil {
		return
	}

	if node.eachRead[id] {
		consume(node.next, id)
	} else {
		node.eachRead[id] = true
		node.read--
		fmt.Printf(node.word + " p%d ", id)
		if node.read == 0 {
		  fmt.Println()
    }
	}
}

func consumer(id int, wg *sync.WaitGroup) {
	defer wg.Done()
	for !finished {
		if list.head != nil {
			mut.Lock()
			consume(list.head, id)
			mut.Unlock()
			time.Sleep(time.Millisecond*200)
		}
	}
}

func main() {
	var (
		producerGroup sync.WaitGroup
		consumerGroup sync.WaitGroup
	)
	consumerGroup.Add(MAX)
	producerGroup.Add(MAX)

	for i := 0; i < MAX; i++ {
		go producer(i,&producerGroup)
	}

	for i := 0; i < MAX; i++ {
		go consumer(i, &consumerGroup)
	}

	for !finished {
		if !producing() && list.head == nil {
			finished = true
			break
		} else {
			words_to_clean := findFinished()
			if len(words_to_clean) != 0 { 
				mut.Lock()
				for _, word := range words_to_clean {
					list.Delete(word)
					
				}
				mut.Unlock()
			}
			time.Sleep(time.Second * 2)
		}
	}
	consumerGroup.Wait()
}

func findFinished() (words []string) {
  node := list.head
  for node != nil {
    if node.read == 0 {
      words = append(words, node.word)    
    }
    node = node.next
  }
  return words
}

func producing() bool {
  for i:= 0; i < MAX;i++ {
    if producerDead[i] {
      return false
    }
  }
  return true
}
