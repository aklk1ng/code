package main

import "fmt"
func main() {
    // const (
    //     // iota only used in const
    //     a = iota // 0
    //     b, d = iota, iota // 1
    //     c = iota // 2
    // )
    // const (
    //     a = iota
    //     b 
    //     c 
    // )
    // fmt.Println("a=",a)
    // fmt.Println(b,c,d)
    
    var a bool
    a = true
    fmt.Println("a=",a)
    // automatic derivation
    var b = false
    fmt.Println("b=",b)
    c := false
    fmt.Println("c=",c)
}
