package main

import (
	"./file"
	"fmt"
	"os"
	"os/signal"
	"syscall"
)

func main() {
	http, _ := filehandle.NewHandler("http", 3, 2, 10)
	http.Start()

	quitCh := make(chan os.Signal, 1)
	signal.Notify(quitCh, syscall.SIGQUIT, syscall.SIGINT)

	for {
		select {
		case <-quitCh:
			fmt.Println("quit~")
			http.Stop()
			return

		}
	}
}
