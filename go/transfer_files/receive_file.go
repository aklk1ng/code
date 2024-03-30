package main

import (
	"fmt"
	"io"
	"net"
	"os"
)

func RecvFile(fileName string, conn net.Conn) {
	f, err := os.Create(fileName)
	if err != nil {
		fmt.Println("os.Create error", err)
		return
	}
	buf := make([]byte, 1024*10)
	var n int
	for {
		n, err = conn.Read(buf)
		if err != nil {
			if err == io.EOF {
				fmt.Println("receive the file over")
			} else {
				fmt.Println("conn.Read error", err)
			}
			return
		}
		if n == 0 {
			fmt.Println("receive the file over")
			break
		}
		// write the new file
		f.Write(buf[:n])
	}

}
func test() {
	listen, err := net.Listen("tcp", "127.0.0.1:8000")
	if err != nil {
		fmt.Println("net.Listen error", err)
		return
	}
	defer listen.Close()

	conn, err := listen.Accept()
	if err != nil {
		fmt.Println("listen.Accept error", err)
		return
	}

	// receive the filename
	defer conn.Close()
	buf := make([]byte, 1024)
	var n int
	n, err = conn.Read(buf)
	if err != nil {
		fmt.Println("conn.Read error", err)
		return
	}
	fileName := string(buf[:n])
	// reply the "ok"
	conn.Write([]byte("ok"))

	// receive the file
	RecvFile(fileName, conn)
}
func main() {
	test()
}
