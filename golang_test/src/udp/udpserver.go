//udp server性能测试 1 ：
// 每次接收数据都new新的buff
package main

import (
	"encoding/json"
	"fmt"
	"net"
	"time"
)

const (
	server_ip = ":32145"
)

type MsgType struct {
	MT string `json:"msgtype"`
}

func main() {
	udp_addr, err := net.ResolveUDPAddr("udp", server_ip)
	if err != nil {
		panic(err)
	}

	conn, err := net.ListenUDP("udp", udp_addr)
	if err != nil {
		panic(err)
	}
	fmt.Println("new conection,", conn.RemoteAddr())
	conn.SetDeadline(time.Now().Add(time.Second * 25))

	go connHandle(conn)

	for {
		time.Sleep(1 * time.Second)
	}
}

var starttime, endtime int64

func connHandle(conn *net.UDPConn) {
	defer conn.Close()
	//defer fmt.Println(endtime)

	var i int
	for {
		buf := make([]byte, 65535)
		fmt.Println("keep reading...")
		n, _, err := conn.ReadFromUDP(buf)

		if i == 0 {
			starttime = time.Now().Unix()
			i++
		}
		if err != nil {
			fmt.Println(err)
			return
		}
		go do(buf, n)
	}
}

func do(buf []byte, n int) {
	fmt.Println(len(buf), cap(buf))
	fmt.Println("read buf ", string(buf))

	mt := new(MsgType)
	err := json.Unmarshal(buf[:n], mt)
	if err != nil {
		fmt.Println(err)
		return
	}

	fmt.Println(mt)

	endtime = time.Now().Unix()

	fmt.Println(endtime - starttime)
}
