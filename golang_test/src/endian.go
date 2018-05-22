package main

import (
	"fmt"
	"unsafe"
)

func main() {
	systemEndian()
}

/*
   判断大小端
  0--大端  1--小端
*/
const INT_SIZE int = int(unsafe.Sizeof(0))

func systemEndian() int {
	fmt.Println("INT_SIZE:", INT_SIZE)
	i := 0x1
	bs := (*[INT_SIZE]byte)(unsafe.Pointer(&i))

	if bs[0] == 0 {
		fmt.Println("little endian!")
		return 1
	} else {
		fmt.Println("big endian!")
		return 0
	}
}
