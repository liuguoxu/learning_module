//测试base64
package main

import (
	"encoding/base64"
	"fmt"
	"os"
)

func main() {
	f, err := os.OpenFile("./testfile", os.O_RDWR|os.O_CREATE, 0666)

	if err != nil {
		panic(err)
	}
	defer f.Close()

	str := "hello"

	en_str := base64.StdEncoding.EncodeToString([]byte(str))
	raw_en_str := base64.RawStdEncoding.EncodeToString([]byte(str))

	fmt.Println([]byte(en_str))
	//	fmt.Println(en_str)
	fmt.Println([]byte(raw_en_str))

	fmt.Println([]byte("aGVsbG8K"))

	f.WriteString(en_str)
}
