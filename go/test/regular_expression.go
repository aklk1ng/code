package main

import (
	"fmt"
	"regexp"
)

func test1() {
    buf := "afc abc 3.14 7. 8.99 1.333  13.14 1.1 qr@sdf 814"

    // reg1 := regexp.MustCompile(`a.c`)
    reg1 := regexp.MustCompile(`\d+\.\d+`)
    if reg1 == nil {
        fmt.Println("error")
        return
    }
    // result := reg1.FindAllString(buf, -1)
    result := reg1.FindAllStringSubmatch(buf, -1)
    fmt.Println(result)
}
func test2() {
    buf := "<div>114<div> <div>sdf<div>"
    reg := regexp.MustCompile(`<div>(.*)<div>`)
    if reg == nil {
        fmt.Println("error")
        return
    }
    result := reg.FindAllStringSubmatch(buf, -1)
    fmt.Println(result)

}

func main() {
    // test1()
    test2()
}
