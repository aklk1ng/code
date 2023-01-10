package main

import (
	"fmt"
	"time"
)

var global_ch = make(chan  int)

func Printer(str string) {
    for _, value := range str {
        fmt.Printf("%c", value)
        time.Sleep(time.Second)
    }
    fmt.Printf("\n")
}
func task1() {
    Printer("hello")
    global_ch <- 666
}
func task2() {
    // it will block if there is no data in the channel
    <- global_ch
    Printer("world")
}
func test() {
    ch := make(chan int)
    // len(ch) -- the size of the channel buffer
    // cap(ch) -- the capacitty of the channel buffer
    fmt.Println(len(ch))
    // go func() {
    //     for i := 0; i < 3; i ++ {
    //         fmt.Println(i)
    //         ch <- i
    //     }
    // }()
    time.Sleep(2 * time.Second)
    for i := 0; i < 3; i ++ {
        num := <- ch
        fmt.Println(num)
    }
}
func test1() {
    ch := make(chan int, 3)
    fmt.Println(len(ch), cap(ch))
    go func() {
        for i := 0; i < 10; i ++ {
            fmt.Printf("sub-coroutine:%d, size:%d, cap:%d\n", i, len(ch), cap(ch))
            ch <- i
        }
    }()
    time.Sleep(2 * time.Second)
    for i := 0; i < 10; i ++ {
        num := <- ch
        fmt.Println(num)
    }
}
func test2() {
    ch := make(chan int, 3)
    fmt.Println(len(ch), cap(ch))
    go func() {
        for i := 0; i < 10; i ++ {
            fmt.Printf("sub-coroutine:%d, size:%d, cap:%d\n", i, len(ch), cap(ch))
            ch <- i
        }
        close(ch)
    }()
    // for num := range ch {
    //     fmt.Println(num)
    // }
    for {
        if num, ok := <- ch; ok == true {
            fmt.Println(num)
        } else {
            break
        }
    }
}
func test3() {
    ch := make(chan int)
    var sendch chan <- int = ch
    var receivech <- chan int = ch
    go func(out chan <- int) {
        for i := 0; i < 10; i ++ {
            out <- i * i
        }
        close(out)
    }(sendch)

    func(in <- chan int) {
        for num := range in {
            fmt.Println(num)
        }
    }(receivech)
}
func main() {
    // test()
    // test1()
    // test2()
    test3()
}
