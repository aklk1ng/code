package main

import (
	"fmt"
	"io/ioutil"
)

func main() {
	files, _ := ioutil.ReadDir(".")
	for _, file := range files {
		fmt.Println(file.Name())
	}
}
