//DES加密测试
package main

import (
	"bytes"
	"crypto/cipher"
	"crypto/des"
	"encoding/base64"
	"fmt"
	"os"
)

func PKCS5Padding(ciphertext []byte, blockSize int) []byte {
	padding := blockSize - len(ciphertext)%blockSize
	padtext := bytes.Repeat([]byte{byte(padding)}, padding)
	return append(ciphertext, padtext...)
}

//DES-CBC加密
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

func DesDecryption(key, iv, cipherText []byte) ([]byte, error) {

	block, err := des.NewCipher(key)

	if err != nil {
		return nil, err
	}

	blockMode := cipher.NewCBCDecrypter(block, iv)
	origData := make([]byte, len(cipherText))
	blockMode.CryptBlocks(origData, cipherText)
	origData = PKCS5UnPadding(origData)
	return origData, nil
}
func PKCS5UnPadding(src []byte) []byte {
	length := len(src)
	unpadding := int(src[length-1])
	return src[:(length - unpadding)]
}

func main() {
	key_str := "pbwj$#@!"
	iv_str := "salt#&@!"

	data := ""

	for i := 0; i < 100; i++ {
		data += "34122610016739\n"
	}
	data = data[0 : len(data)-1]
	fmt.Println("data len:", len(data))

	en_data, err := encryt([]byte(data), []byte(key_str), []byte(iv_str))
	if err != nil {
		fmt.Println(err)
		return
	}

	fmt.Println(string(en_data))

	os.Remove("jiami")

	f, _ := os.OpenFile("jiami", os.O_RDWR|os.O_CREATE, 0666)

	defer f.Close()

	en_str := base64.StdEncoding.EncodeToString(en_data) + "\n"

	f.WriteString(en_str)

	//de, _ := DesDecryption([]byte(key_str), []byte(iv_str), en_data)
	//fmt.Println("de:", string(de))
}
