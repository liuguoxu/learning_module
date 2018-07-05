//测试 kill -9 defer 能否生效
package main

import "time"
import "fmt"

func main() {
	defer func() {
		fmt.Println("defer func")
		time.Sleep(2 * time.Second)
		fmt.Println("defer func")
		fmt.Println("defer func")
	}()

	for {
		time.Sleep(2 * time.Second)
		//		return
	}
}
