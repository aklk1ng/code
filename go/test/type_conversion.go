package main

import (
	"fmt"
	"strconv"
)

func main() {
	// there are type incompatibilites
	var a int
	var b float64
	b = 3.14
	a = int(b)
	ch := 'a'
	var t int
	t = int(ch)
	var c string
	c = strconv.Itoa(a)
	fmt.Println(b)
	fmt.Println(a)
	fmt.Println(t)
	fmt.Printf("%v,%T\n", c, c)
}
