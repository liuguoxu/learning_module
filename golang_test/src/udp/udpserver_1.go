//udp server性能测试 2 ：
// 使用buff pool
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
	go connHandle(conn)

	for {
		time.Sleep(1 * time.Second)
	}
}

var starttime, endtime int64

type mybuf struct {
	buf      []byte
	occupied bool //is this buf occupied
}

func (this *mybuf) Occupy() {
	this.occupied = true
}

func (this *mybuf) Done() {
	this.occupied = false
	//fmt.Println("i am done")
}

var buffers []*mybuf

func GetBuf() *mybuf {
	for _, v := range buffers {
		if !v.occupied {
			v.occupied = true
			return v
		}
	}
	fmt.Println("buffers not enough, new one")

	b := &mybuf{buf: make([]byte, 65535), occupied: true}
	buffers = append(buffers, b)
	return b
}

func connHandle(conn *net.UDPConn) {
	defer conn.Close()
	defer fmt.Println(endtime)

	buffers = make([]*mybuf, 1)
	buffers[0] = &mybuf{buf: make([]byte, 65535), occupied: false}

	var buf *mybuf
	var i int
	for {

		fmt.Println("keep reading...")

		buf = GetBuf()
		n, _, err := conn.ReadFromUDP(buf.buf)

		if i == 0 {
			starttime = time.Now().Unix()
			i++
		}
		if err != nil {
			panic(err)
		}
		go do(buf, n)
	}
}

func do(buf *mybuf, n int) {
	fmt.Println(len(buf.buf), cap(buf.buf))
	fmt.Println("read buf ", string(buf.buf))

	mt := new(MsgType)
	err := json.Unmarshal(buf.buf[:n], mt)
	if err != nil {
		fmt.Println(err)
		return
	}

	fmt.Println(mt)
	endtime = time.Now().Unix()

	fmt.Println(endtime - starttime)

	//buf.Done()
	buf.occupied = false
}
