package main

import (
	"fmt"
)

func main() {
	// type alias
	type bigint int64
	var a bigint
	a = 1
	fmt.Printf("a:%T\n", a)
	fmt.Println(a)
}
