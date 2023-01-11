package main

import (
	"fmt"
	"net"
	"os"
)

func test() {
    // connect the server
    conn, err := net.Dial("tcp", "127.0.0.1:8000")
    if err != nil {
        fmt.Println(err)
        return
    }
    defer conn.Close()
    go func() {
        str := make([]byte, 1024 * 2) // read bytes from the  stdin
        for {
            n, err := os.Stdin.Read(str) // receive server request
            if err != nil {
                fmt.Println("os.stdin err" ,err)
                return
            }
            conn.Write(str[:n])
        }
    }()

    buf := make([]byte, 1024 * 2)
    for {
        n, err := conn.Read(buf) // receive server request
        if err != nil {
            fmt.Println("conn.read err" ,err)
            return
        }
        fmt.Println(string(buf[:n]))
    }
}
func main() {
    test()
}
