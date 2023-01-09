package main

import (
	"fmt"
)

func test1() {
    fmt.Println("call test")
}
func test2(x int, y int) int{
    return x + y
}

// args ... type -- variable parameter(only used in the last parameter)
func test3(args ... int) {
    test4(args ...)
    test4(args[1:2]...)
}

func test4(tmp ... int) {
    fmt.Println(tmp)
}

func test5(a, b int) (int, int){
    return b, a
}

func update(s2 []int) {
    fmt.Println(s2)
    s2[1] = 0
    fmt.Println(s2)
}

func string(s [4]int) {
    s[1] = 0 
}

func recursion(a int) int{
    if a == 1 {
        return 1
    }
    return recursion(a - 1) + a
}
func F(i any) {
    fmt.Println(i)
}
func main() {
    // test1()
    s1 := []int{1,2,3,4,5}
    str := [4]int{1,2,3,4}
    // res := test2(1, 2)
    // const usl = "wwww.google.com"
    // fmt.Println(usl)
    // fmt.Println(res)
    // fmt.Println(s1)
    // update(s1)
    // fmt.Println(s1)
    // string(str)
    // fmt.Println(str)
    // a := recursion(5)
    // fmt.Println(a)
    test3(1,2,3,4)
    // a,b := test5(1,2)
    // fmt.Println(a,b)

    f3 := func() {
        fmt.Println("call the f3()")
    }
    func() {
        fmt.Println("call the f4()")
    }()

    fmt.Println(s1)
    defer F(str) // pass the parameter now but excute finally
    fmt.Println(s1)
    defer F(s1)
    fmt.Println(s1)
    fmt.Printf("%T\n", test5)
    f3()
}
