package main

import (
	"crypto/rand"
	"math/big"
	"os"
)

// Function to generate a random string of specified length
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

func main() {
	// Generating a random string of length 10
	var strings string
	for i := 1; i <= 50; i++ {
		strings = strings + " " + randomString(4)

	}
	err := os.WriteFile("data.txt", []byte(strings), 0644)
	if err != nil {
		return
	}

}
