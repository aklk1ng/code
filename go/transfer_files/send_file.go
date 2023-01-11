package main

import (
	"fmt"
	"io"
	"net"
	"os"
)
func SendFile(path string, conn net.Conn) {
    f, err := os.Open(path)
    if  err != nil {
        fmt.Println("os.Open error" ,err)
        return
    }
    defer f.Close()
    buf := make([]byte, 1024 * 2)
    for {
        n, err := f.Read(buf) // read from the file
        if  err != nil {
            if err == io.EOF {
                fmt.Println("The file is over")
            } else {
                fmt.Println("f.Read error" ,err)
            }
            return
        }
        conn.Write(buf[:n]) // send to server
    }
}

func test() {
    fmt.Println("Please enter the file:")
    var path string
    fmt.Scan(&path)
    info, err := os.Stat(path)
    if  err != nil {
        fmt.Println("os.Stat error" ,err)
        return
    }
    // connect the server
    conn, err := net.Dial("tcp", "127.0.0.1:8000")
    if  err != nil {
        fmt.Println("net.Dial error" ,err)
        return
    }
    defer conn.Close()
    // send the filename
    _, err = conn.Write([]byte(info.Name()))
    if  err != nil {
        fmt.Println("conn.Write error" ,err)
        return
    }

    var n int
    buf := make([]byte, 1024)
    n, err = conn.Read(buf)
    if  err != nil {
        fmt.Println("conn.Read error" ,err)
        return
    }
    if "ok" == string(buf[:n]) {
        SendFile(path, conn)
    }
}
func main() {
    test()
}
