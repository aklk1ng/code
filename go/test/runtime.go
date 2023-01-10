package main

import (
	"fmt"
	"runtime"
	// "time"
)

func task1() {
    i := 0
    for ; i < 10; i ++ {
        fmt.Printf("%d\n", i)
        if i == 5 {
            // terminate the coroutine
            runtime.Goexit()
        }
    }
}
func task2() {
    
}
func main() {
    runtime.GOMAXPROCS(2)
    go task1() 
    // i := 0
    for {
        go fmt.Print(1)
        fmt.Print(0)
        // time.Sleep(time.Second)
    }
    // for ; i < 10; i ++ {
    //     runtime.Gosched()
    //     fmt.Printf("%d\n", i)
    //     time.Sleep(time.Second)
    // }
}
