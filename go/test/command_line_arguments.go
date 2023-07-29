package main

import (
	"fmt"
	"os"
)

func main() {
	list := os.Args
	// n := len(list)
	// fmt.Println(n)
	// for i := 0; i < n; i ++ {
	//     fmt.Printf("%s", list[i])
	// }
	for i := range list {
		fmt.Println(list[i])
	}
}
