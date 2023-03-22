package main

import (
	"fmt"
	"net"
	"strings"
)

func HandleConn(conn net.Conn) {
	defer conn.Close()
	addr := conn.RemoteAddr().String()
	fmt.Printf("addr %s connect successful\n", addr)
	buf := make([]byte, 1024*2)
	for {
		n, error := conn.Read(buf)
		if error != nil {
			fmt.Println(error)
			return
		}
		fmt.Println(addr, string(buf[:n]))
		fmt.Println(len(string(buf[:n])))
		if "exit" == string(buf[:n-1]) {
			fmt.Println("Welcome!")
			return
		}
		conn.Write([]byte(strings.ToUpper(string(buf[:n]))))
	}

}
func test() {
	listen, err := net.Listen("tcp", ":8000")
	if err != nil {
		fmt.Println(err)
		return
	}
	defer listen.Close()
	for {
		conn, err := listen.Accept()
		if err != nil {
			fmt.Println(err)
			return
		}
		go HandleConn(conn)
	}
}
func main() {
	test()
}
