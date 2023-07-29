package main

import (
	"fmt"
	"time"
)

func test() {
	timer := time.NewTimer(1 * time.Second)
	fmt.Println(time.Now())
	// respond only once
	t := <-timer.C
	fmt.Println(t)
}
func test1() {
	timer := time.NewTimer(3 * time.Second)
	go func() {
		<-timer.C
		fmt.Printf("The time is over")
	}()
	timer.Stop()
}
func test2() {
	timer := time.NewTimer(3 * time.Second)
	timer.Reset(1 * time.Second)
	<-timer.C
	fmt.Printf("The time is over")
}
func main() {
	// test()
	// test1()
	test2()
}
