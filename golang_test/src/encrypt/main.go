//des加密测试
package main

import (
	"bytes"
	"crypto/cipher"
	"crypto/des"
	//	"encoding/base64"
	"fmt"
	"os"
)

func PKCS5Padding(ciphertext []byte, blockSize int) []byte {
	padding := blockSize - len(ciphertext)%blockSize
	padtext := bytes.Repeat([]byte{byte(padding)}, padding)
	return append(ciphertext, padtext...)
}

func encryt(data, key, iv []byte) ([]byte, error) {
	blk, err := des.NewCipher(key)
	if err != nil {
		fmt.Println(err)
		return nil, err
	}

	data = PKCS5Padding(data, blk.BlockSize())

	blk_mode := cipher.NewCBCEncrypter(blk, iv)

	en_data := make([]byte, len(data))

	blk_mode.CryptBlocks(en_data, data)

	return en_data, nil
}

func main() {
	fmt.Println("ok")

	key_str := "pbwj$#@!"
	iv_str := "salt#&@!"

	f, _ := os.OpenFile("jiami", os.O_RDWR|os.O_CREATE, 0666)

	data := "hello world"

	en_data, _ := encryt([]byte(data), []byte(key_str), []byte(iv_str))

	//	base_str := base64.StdEncoding.EncodeToString([]byte("good~"))

	//	fmt.Println(base_str)
	//	f.WriteString(base_str)
	f.Write(en_data)

	f.Close()
}
