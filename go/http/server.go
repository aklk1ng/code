package main

import (
	"fmt"
	"net"
	"net/http"
)

func Get() {
	listen, err := net.Listen("tcp", ":8000")
	if err != nil {
		fmt.Println("net.Listen error", err)
		return
	}
	defer listen.Close()
	conn, error := listen.Accept()
	if error != nil {
		fmt.Println("listen.Accept error", error)
		return
	}
	defer conn.Close()

	// receive client data
	buf := make([]byte, 1024*4)
	n, err1 := conn.Read(buf)
	if n == 0 {
		fmt.Println(err1)
		return
	}
	fmt.Printf("#%v#\n", string(buf[:n]))
}

// reply client data
// read data from client
func HandleConn(w http.ResponseWriter, req *http.Request) {
	w.Write([]byte("hello go"))
}

func Request() {
	http.HandleFunc("/", HandleConn)
	http.ListenAndServe(":8000", nil)
}

func main() {
	// Get()
	Request()
}
