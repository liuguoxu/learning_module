package main

import "fmt"

type dog struct {
	a int
}

func (dog) Speak() {
	fmt.Println("I am a dog")
}

type FOO interface {
	Speak()
}

var _ FOO = dog{}

func main() {
	fmt.Println("good")
}
