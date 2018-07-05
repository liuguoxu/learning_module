package main

import (
	"fmt"
	"net"
	"sync"
	"time"
)

const (
	server_ip = ":32145"

	READ_BUF_LEN = 128
)

func main() {
	listen, err := net.Listen("tcp4", server_ip)

	if err != nil {
		panic(err)
	}

	var conn net.Conn
	wg := &sync.WaitGroup{}
	go func() {
		for {
			fmt.Println("start listen")
			conn, err = listen.Accept()
			if err != nil {
				fmt.Println(err)
			}
			fmt.Println("got a conn!", conn.RemoteAddr().String())

			go connHandle(conn, wg)

		}
	}()

	time.Sleep(time.Second * 5)
	conn.Close()
	wg.Wait()
	fmt.Println("wg done")
	time.Sleep(time.Second * 2)
}

func connHandle(conn net.Conn, wg *sync.WaitGroup) {
	wg.Add(1)
	defer wg.Done()
	defer fmt.Println(conn.Close())
	buf := make([]byte, READ_BUF_LEN)

	err_times := 0
	for {
		if n, err := conn.Read(buf); err != nil {
			fmt.Println(err)
			if err_times >= 3 {
				fmt.Println("error more than 3 times,close connection!")
				return
			}
			err_times++
		} else {
			fmt.Println(string(buf), n)
			err_times = 0
		}
	}
}
