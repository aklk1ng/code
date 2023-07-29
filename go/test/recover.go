package main

import "fmt"

func test(x int) {
	defer func() {
		if err := recover(); err != nil {
			fmt.Println(err)
		}
	}()
	var a [10]int
	a[x] = 111
}
func main() {
	test(20)
}
