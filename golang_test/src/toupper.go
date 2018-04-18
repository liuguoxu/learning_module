package main

import (
	"fmt"
	"strings"
)

func main() {
	str := "peter"
	tmp := strings.ToTitle(str)
	fmt.Println(tmp)
	fmt.Println(str)
}
