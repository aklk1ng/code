package main

import (
	"fmt"
	"time"
)

func newTask() {
	i := 0
	for {
		i++
		fmt.Printf("🐒:%d\n", i)
		time.Sleep(time.Second)
	}
}
func main() {
	i := 0
	go newTask()
	for {
		i++
		fmt.Printf("🐑:%d\n", i)
		time.Sleep(time.Second)
		if i == 10 {
			break
		}
	}
}
