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

	str := `qwertndkljsanhfiusdhfi2379r023jure  0234e8  1mdkslajdkofpoa8w0r423  m4ek3jr9038240  2j3rekl;asofdpus90af80-wr3324p2ojrokjdslkfhdisoahfodsffdnshalkjfksdufioue
    fjoidsaufuwepofjkosdjvaoijdspofiewurpr-32SD902u3irjsalkjfkldsjioufpeupaUIRE908W  UI9321I418-243102  JFDSOPJFAOIPSD8F0W304E  REOWPQJDOPESJAFPDSOPFUIOPEWUFQW
    JRKWOEQURqwertndkljsanhfiusdhfi2379r023jure  0234e8  1mdkslajdkofpoa8w0r423  m4ek3jr9038240  2j3rekl;asofdpus90af80-wr3324p2ojrokjdslkfhdisoahfodsffdnshalkjfksdufioue
    fjoidsaufuwepofjkosdjvaoijdspofiewurpr-32r902u3irjsalkjfkldsjioufpeupaUIRE908W  UI9321I418-243102  JFDSOPJFAOIPSD8F0W304E  REOWPQJDOPESJAFPDSOPFUIOPEWUFQW
    JRKWOEQURqwertndkljsanhfiusdhfi2379r023jure  0234e8  1mdkslajdkofpoa8w0r423  m4ek3jr9038240  2j3rekl;asofdpus90af80-wr3324p2ojrokjdslkfhdisoahfodsffdnshalkjfksdufioue
    fjoidsaufuwepofjkosdjvaoijdspofiewurpr-32r902u3irjsalkjfkldsjioufpeupaUIRE908W  UI9321I418-243102  JFDSOPJFAOIPSD8F0W304E  REOWPQJDOPESJAFPDSOPFUIOPEWUFQW
    JRKWOEQURqwertndkljsanhfiusdhfi2379r023jure  0234e8  1mdkslajdkofpoa8w0r423  m4ek3jr9038240  2j3rekl;asofdpus90af80-wr3324p2ojrokjdslkfhdisoahfodsffdnshalkjfksdufioue
    fjoidsaufuwepofjkosdjvaoijdspofiewurpr-32r902u3irjsalkjfkldsjioufpeupaUIRE908W  UI9321I418-243102  JFDSOPJFAOIPSD8F0W304E  REOWPQJDOPESJAFPDSOPFUIOPEWUFQW
    JRKWOEQURqwertndkljsanhfiusdhfi2379r023jure  0234e8  1mdkslajdkofpoa8w0r423  m4ek3jr9038240  2j3rekl;asofdpus90af80-wr3324p2ojrokjdslkfhdisoahfodsffdnshalkjfksdufioue
    fjoidsaufuwepofjkosdjvaoijdspofiewurpr-32r902u3irjsalkjfkldsjioufpeupaUIRE908W  UI9321I418-243102  JFDSOPJFAOIPSD8F0W304E  REOWPQJDOPESJAFPDSOPFUIOPEWUFQW
    JRKWOEQURqwertndkljsanhfiusdhfi2379r023jure  0234e8  1mdkslajdkofpoa8w0r423  m4ek3jr9038240  2j3rekl;asofdpus90af80-wr3324p2ojrokjdslkfhdisoahfodsffdnshalkjfksdufioue
    fjoidsaufuwepofjkosdjvaoijdspofiewurpr-32r902u3irjsalkjfkldsjioufpeupaUIRE908W  UI9321I418-243102  JFDSOPJFAOIPSD8F0W304E  REOWPQJDOPESJAFPDSOPFUIOPEWUFQW
    JRKWOEQUR`

	conn, err := net.DialTimeout("udp", server_ip, 2*time.Second)
	if err != nil {
		panic(err)
	}
	fmt.Println("connect success!")

	for {

		times := 1
		fmt.Println("new times")
		for { //尝试3次发送，都失败则删除该用户，断开连接
			fmt.Println("start send message")
			if _, err = conn.Write([]byte(str)); err != nil {
				fmt.Println(err, times)
				if times >= 3 {
					fmt.Println("send message retry for", times, "close connection!")
					conn.Close()
					return
				}
				times++
				time.Sleep(time.Second * 1)
			} else {
				fmt.Println("send success:", server_ip, len(str))
				time.Sleep(2 * time.Second)
				break
			}
		}

	}
}
