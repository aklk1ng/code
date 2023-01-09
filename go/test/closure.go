package main

import "fmt"

func increment() func() int {
    i := 0
    fun := func() int {
       i ++ 
        return i
    }
    return fun
}

func main() {
    r := increment()    
    v := r()
    fmt.Println(v)
    v = r()
    fmt.Println(v)
    v = r()
    fmt.Println(v)
    v = r()
    fmt.Println(v)
    v = r()
    fmt.Println(v)
    fmt.Printf("----------------------\n")

    v2 := increment()
    res := v2()
    fmt.Println(res)
    res = v2()
    fmt.Println(res)
    res = v2()
    fmt.Println(res)
    res = v2()
    fmt.Println(res)
    fmt.Printf("----------------------\n")

    fmt.Println(v)
}
