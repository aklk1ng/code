package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
)

func WriteFile(path string) {
    f, err := os.Create(path)
    if err != nil {
        fmt.Println(err)
        return
    }
    defer f.Close()
    var buf string
    for i := 0; i < 10; i ++ {
        buf = fmt.Sprintf("i = %d\n", i)
        n, err := f.WriteString(buf)
        if err != nil {
            fmt.Println(err)
            return
        }
        fmt.Println(n)
    }
}
func ReadFile(path string) {
    // read by byte
    f, err := os.Open(path)
    if err != nil {
        fmt.Println(err)
        return
    }
    defer f.Close()
    buf := make([]byte, 1024*2)
    n, error := f.Read(buf)
    if error != nil && error != io.EOF {
        fmt.Println(error)
        return
    }
    fmt.Println(string(buf[:n]))
}
func ReadFileLine(path string) {
    f, err := os.Open(path)
    if err != nil {
        fmt.Println(err)
        return
    }
    defer f.Close()

    r := bufio.NewReader(f)
    for {
        buf, err := r.ReadBytes('\n')
        if err != nil {
            if err == io.EOF {
                break;
            }
            fmt.Println(err)
        }
        fmt.Println(string(buf))
    }
}
func test() {
    path := "./files/test.txt"
    // WriteFile(path)
    // ReadFile(path)
    ReadFileLine(path)
}

func main() {
    test()
}
