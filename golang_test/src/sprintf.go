package main

import "fmt"

func main() {
	num := 12

	num_str := fmt.Sprintf("%03d", num)

	fmt.Println(num_str)

	fmt.Println(num_str[0:1], num_str[1:3])
}
