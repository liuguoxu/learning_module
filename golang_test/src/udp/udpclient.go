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

	str := `{
    "msgtype": "WA_SOURCE_IK_0001",
    "data": {
        "C020009": "Unknown",
        "C020011": "Unknown",
        "C040002": "B0-89-00-31-99-18",
        "DATA_SRC_CODE": "530124",
        "F020001": "3232235779",
        "F030011": "A8-58-40-DF-DC-E0",
        "G020004": "53012421931079",
        "G030004": "3010015",
        "H010013": "53012421931079b089003199181530500925",
        "H010015": "1530503871",
        "H010016": "1530504648",
        "I070011": "069567814A85840DFDCE0",
        "LOG_TIME": "1530784465"
    }
}
 `

	conn, err := net.DialTimeout("udp", server_ip, 2*time.Second)
	if err != nil {
		panic(err)
	}
	fmt.Println("connect success!")

	conn.SetDeadline(time.Now().Add(time.Second * 3))

	for {

		if _, err = conn.Write([]byte(str)); err != nil {
			fmt.Println(err)
			return
		} else {
			fmt.Println("send success:", server_ip, len(str))
			//time.Sleep(2 * time.Second)
		}

	}
}
