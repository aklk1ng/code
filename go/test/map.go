package main

import "fmt"

func main() {
	m := map[int]int{1: 1, 2: 2, 3: 3}
	delete(m, 1)
	c := map[int]string{1: "xxx", 2: "ooo"}
	value, ok := c[1]
	if ok {
		fmt.Println(value)
	} else {
		fmt.Printf("Error\n")
	}
	for key, value := range m {
		fmt.Println(key, value)
	}
}
