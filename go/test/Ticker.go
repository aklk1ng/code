package main

import (
	"fmt"
	"time"
)

func test() {
    ticker := time.NewTicker(3 * time.Second)
    for i := 0; i < 20; i ++ {
         <- ticker.C
        fmt.Printf("The time is over")
    }
}
func main() {
    test() 
}
