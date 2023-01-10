package main

import (
	"fmt"
	"time"
)

func fibo(ch chan <- int, quit <- chan bool) {
    x, y := 1, 1
    for {
        select {
        case ch <- x:
            x, y = y, x + y
        case flag := <- quit:
            fmt.Println(flag)
            return
        }
    }
}
func test(ch chan int, quit chan bool) {
    go func() {
        for i := 0; i < 12; i ++ {
            num := <- ch
            fmt.Println(num)
        }
        quit <- true
    }()
}
func test1(ch chan int, quit chan bool) {
    func() {
        for {
            select {
            case num := <- ch:
                fmt.Println(num)
            case <- time.After(3 * time.Second):
                fmt.Printf("over1")
                quit <- true
                break
            }
        }
    }()
}
func main() {
    ch := make(chan int)
    quit := make(chan bool)
    // test(ch, quit)
    go test1(ch, quit)
    for i := 0; i < 5; i++ {
        ch <- i
    }
    <- quit
    fmt.Printf("over2")
    // fibo(ch, quit)
}
