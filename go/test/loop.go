package main

import (
	"fmt"
	"time"
)

func main() {
	for num := 1; num <= 10; num++ {
		fmt.Println(num)
		if num == 5 {
			continue // only used in loop, break the next code in the loop
		}
		if num == 6 {
			break
		}
	}

	str := "Hello"
	fmt.Printf("%s\n", str)
	for i := 0; i < len(str); i++ {
		fmt.Printf("%c\n", str[i])
	}

	for i := range str {
		fmt.Printf("%d->%c\n", i, str[i])
	}

	j := 0
	for {
		j++
		time.Sleep(time.Second)
		if j == 3 {
			continue
		}
		if j == 5 {
			break // break the nextest loop
		}
		fmt.Println(j)
	}
}
