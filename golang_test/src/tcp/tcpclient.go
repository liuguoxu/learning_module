package main

import (
	"bytes"
	"encoding/hex"
	"fmt"
	"net"
	"time"
)

const (
	server_ip = ":32145"
	json_str  = `{"first": 123, "second": "123","third": true}`

	DIAL_TIMEOUT  = 2 //dial超时时间
	TCP_MAX_RETRY = 3 //tcp连接尝试最大次数
)

func main() {
	var (
		err   error
		conn  net.Conn
		times = 1
	)
	for {
		fmt.Println("Start dial..")
		if conn, err = net.DialTimeout("tcp4", server_ip, DIAL_TIMEOUT*time.Second); err != nil {
			fmt.Println(err)
			if times >= TCP_MAX_RETRY {
				fmt.Println("TCP connect retry for", times, "times.Connect failed!")
				return
			}
			times++
			time.Sleep(time.Second * 1)
		} else {
			break
		}
	}

	if err != nil {
		panic(err)
	}

	fmt.Println("dial success")
	defer conn.Close()

	len_byte, err := getStrlenByte(json_str)

	data := combineByte(len_byte, []byte(json_str))
	fmt.Println(string(data))

	for {
		fmt.Println("start send data")
		if n, err := conn.Write(data); err != nil {
			fmt.Println(err)
		} else {
			fmt.Println("send success:", n)
		}
		time.Sleep(time.Second * 1)
	}

}

/*
   获取字符串长度，单位[]byte，最大两字节，不足补零
*/
func getStrlenByte(str string) ([]byte, error) {
	strlen := len(str)
	fmt.Println(strlen)
	if strlen > 65535 {
		return nil, fmt.Errorf("strlen is too long\n")
	}

	len_16 := fmt.Sprintf("%04x", strlen)

	len_byte, err := hex.DecodeString(len_16)
	if err != nil {
		panic(err)
	}

	return len_byte, nil
}

/*
   将多个[]byte合并为一个[]byte
*/
func combineByte(pBytes ...[]byte) []byte {
	return bytes.Join(pBytes, []byte(""))
}
