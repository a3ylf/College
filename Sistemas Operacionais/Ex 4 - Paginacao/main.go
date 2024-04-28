package main

import "fmt"

func main() {
	var quadros int
	fmt.Print("Digite o número de quadros: ")
	fmt.Scanln(&quadros)

	fmt.Print("Digite a sequência de números separados por espaço: ")
	Sequence := lerSequencia()

	acessarMemoria(quadros, Sequence)
}

func lerSequencia() []int {
	var elemento int
	var sequencia []int
	for {
		_, err := fmt.Scanf("%d", &elemento)
		if err != nil {
			break
		}
		sequencia = append(sequencia, elemento)
	}
	return sequencia
}

func acessarMemoria(quadros int, Sequence []int) {

	current := []int{}
	toLeave := 0
	pageFaults := 0
	for i := range current {
		current[i] = -1
	}
	for _, value := range Sequence {
		if !contains(current, value) {
			if len(current) < quadros {
				current = append(current, value)
			} else {
				current[toLeave] = value
				toLeave++
				if toLeave == quadros {
					toLeave = 0
				}
			}
			pageFaults++
			fmt.Print(current)
			fmt.Print("| Page Fault")
		} else {
			fmt.Print(current)
		}
		fmt.Println()
	}
	fmt.Println("Numero de Page Faults: ", pageFaults)
}

func contains(current []int, value int) bool {
	for _, currentValue := range current {
		if currentValue == value {
			return true
		}
	}
	return false
}
