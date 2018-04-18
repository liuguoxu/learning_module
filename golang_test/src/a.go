package main

import (
	"fmt"
)

func main() {
	a := make([]int, 0, 10)
	b := append(a, 1)
	fmt.Println(b)
	_ = append(a, 2)
	fmt.Println(b)
	fmt.Println(a)
}
