package main

import "fmt"

type Phone interface {
	Call()
}

type Apple string

func (a Apple) Call() {
	fmt.Println("test")	
}

func main() {
	map1 := make(map[int]int)
	map1[1] = 1
	map1[2] = 2
	map1[3] = 3
	map1[4] = 4
	for key, value := range map1 {
		println(key, value)
	}
}
