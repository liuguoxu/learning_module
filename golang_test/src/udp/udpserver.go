package main

import (
	"fmt"
	"net"
	"time"
)

const (
	server_ip = ":32145"
)

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
	go connHandle(conn)

	for {
		time.Sleep(1 * time.Second)
	}
}

func connHandle(conn *net.UDPConn) {
	defer conn.Close()

	buf := make([]byte, 65535)
	for {
		fmt.Println("keep reading...")
		n, addr, err := conn.ReadFromUDP(buf)

		if err != nil {
			panic(err)
		}

		fmt.Println("read from ", addr, "lenth ", n, "buf", string(buf))
	}
}
