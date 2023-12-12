package main

import (
	"fmt"
	"os"
	"strings"
)

type Node struct {
	data string
	next *Node
}

func newNode(value string) *Node {
	return &Node{data: value, next: nil}
}

func insertNode(head *Node, value string) *Node {
	newNode := newNode(value)
	if head == nil {
		return newNode
	}
	current := head
	for current.next != nil {
		current = current.next
	}
	current.next = newNode
	return head
}

// Função para imprimir os elementos da lista encadeada
func displayList(head *Node) {
	current := head
	for current != nil {
		fmt.Printf("%v -> ", current.data)
		current = current.next
	}
	fmt.Println("nil")
}

func searchAndTransposition(head *Node, value string) string {
	current := head
	position := 0
	var prev *Node
	if current.next.data == value {
		return fmt.Sprintf("String encontrada na posição zero")
	}
	for current != nil {
		if current.data == value {

			temp := prev.data
			prev.data = current.data
			current.data = temp
			return fmt.Sprintf("A string %v estava na posição %v,"+
				" e agora foi para a posição %v", value, position, position-1)
		}
		prev = current
		current = current.next
		position++
	}

	return fmt.Sprintf("A string %v não foi encontrada", value)

}
func searchAndMoveToHead(head *Node, value string) string {
	current := head
	var prev *Node
	position := 0
	if current.next.data == value {

		return fmt.Sprintf("String encontrada na posição zero")

	}
	for current != nil {
		if current.data == value {
			prev.next = current.next
			temp := head.next
			head.next = current
			current.next = temp
			return fmt.Sprintf("A string %v estava na posição %v,"+
				" e agora foi para a posição zero", value, position)
		}
		prev = current
		current = current.next
		position++
	}

	return fmt.Sprintf("A string %v não foi encontrada", value)

}

func main() {
	var head *Node
	file, err := os.ReadFile("data.txt")
	if err != nil {
		return
	}
	randomWords := strings.Split(string(file), " ")
	for _, words := range randomWords {
		head = insertNode(head, words)

	}

	// Exibindo os elementos da lista encadeada
	fmt.Println("Lista encadeada:")

	displayList(head)
	fmt.Println(searchAndTransposition(head, "FODh"))
	displayList(head)
	fmt.Println(searchAndMoveToHead(head, "QCvv"))
	displayList(head)

}
