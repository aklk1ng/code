package main

import "fmt"

func main() {
    // p := new(int)
    // *p = 1
    // fmt.Println(*p)
    // fmt.Println(p)
    a,b := 1, 2
    fmt.Println(a, b)
    p := new(int)
    *p = b
    b = a
    a = *p
    fmt.Println(a, b)
}
