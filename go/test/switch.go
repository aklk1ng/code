package main

import (
	"fmt"
)

func main() {
	var x interface{}
	num := 1
	switch i := x.(type) {
	case nil:
		fmt.Printf("nil-%v\n", i)
	}
	switch {
	case num == 1:
		fmt.Println(num)
		// doesn't break the switch and excute the next confition code
		fallthrough
	case num == 2:
		fmt.Printf("Yes")
	case num == 3:
		fmt.Printf("Error")
	default:
		fmt.Printf("Default")
	}
}
