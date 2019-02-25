package main

import (
	"fmt"
	"time"
)

func main() {
	periods := []int64{1, 2, 3, 4}

	tickers := make(map[int64]*time.Ticker)

	for _, v := range periods {
		t := time.NewTicker(time.Second * time.Duration(v))

		tickers[v] = t
	}

	for {
		for i, tk := range tickers {
			select {
			case <-tk.C:
				fmt.Println("ticker", i, "tick~")

			default:
				continue
			}
		}
	}
}
