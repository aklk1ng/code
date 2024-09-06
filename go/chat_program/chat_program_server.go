package main

import (
	"fmt"
	"net"
	"strings"
	"time"
)

type Client struct {
	C    chan string // the channel to send data
	Name string
	Addr string
}

var onlineUserMap map[string]Client

var message = make(chan string)

func WriteMsgToClient(cli Client, conn net.Conn) {
	for msg := range cli.C {
		conn.Write([]byte(msg + "\n"))
	}
}

func MakeMsg(cli Client, msg string) (buf string) {
	buf = "[" + cli.Addr + "]" + cli.Name + ": " + msg
	return buf
}

func Manager() {
	onlineUserMap = make(map[string]Client)
	for {
		msg := <-message
		for _, value := range onlineUserMap {
			value.C <- msg
		}
	}
}

func HandleConn(conn net.Conn) {
	defer conn.Close()
	cliAddr := conn.RemoteAddr().String()
	// the Name and the Addr is same
	cli := Client{make(chan string), cliAddr, cliAddr}
	// add the struct to the onlineUserMap
	onlineUserMap[cliAddr] = cli

	// send message to current client
	go WriteMsgToClient(cli, conn)

	// broadcast the login message
	message <- MakeMsg(cli, "login")

	isQuit := make(chan bool)
	isChat := make(chan bool)
	// receive the user data
	go func() {
		buf := make([]byte, 2048)
		for {
			n, err := conn.Read(buf)
			if n == 0 {
				isQuit <- true
				fmt.Println("conn.Read error", err)
				return
			}
			msg := string(buf[:n-1])
			// fmt.Println(len(msg))
			if len(msg) == 3 && msg == "who" {
				conn.Write([]byte("User list:\n"))
				for _, value := range onlineUserMap {
					msg = value.Addr + ":" + value.Name + "\n"
					conn.Write([]byte(msg))
				}
			} else if len(msg) >= 8 && msg[:6] == "rename" {
				name := strings.Split(msg, ":")[1]
				cli.Name = name
				onlineUserMap[cliAddr] = cli
				conn.Write([]byte("Change the name successful!\n"))
			} else if len(msg) == 6 && msg == "whoami" {
				msg = cli.Name + "\n"
				conn.Write([]byte(msg))
			} else {
				message <- MakeMsg(cli, msg)
			}

			isChat <- true
		}
	}()

	for {
		// user logout
		select {
		case <-isQuit:
			delete(onlineUserMap, cliAddr)
			message <- MakeMsg(cli, "logout")
			return
		case <-isChat:
		case <-time.After(60 * time.Second):
			delete(onlineUserMap, cliAddr)
			message <- MakeMsg(cli, "leave")
			return
		}
	}
}

func main() {
	listen, err := net.Listen("tcp", ":8000")
	if err != nil {
		fmt.Println("net.Listen error", err)
		return
	}
	defer listen.Close()

	go Manager()

	for {
		conn, err := listen.Accept()
		if err != nil {
			fmt.Println("Listen.Accept error", err)
			continue
		}
		// handle user connections
		go HandleConn(conn)
	}
}
