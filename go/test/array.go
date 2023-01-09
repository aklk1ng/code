package main

import "fmt"

func swap(p *[5]int) {
    (*p)[0],(*p)[len(*p) - 1] = (*p)[len(*p) - 1],(*p)[0]
}
func main() {
    a := [5]int{1,4,10,22,5}
    swap(&a)
    fmt.Println(a)
    // b := [2][3]int{1: {3,4}}
    // fmt.Println(b)

    // bubble sort
    for i := 0; i < len(a); i ++ {
        for j := i + 1; j < len(a); j ++ {
            if a[i] > a[j] {
                a[i],a[j] = a[j], a[i]
            }
        }
    }
    fmt.Println(a)
}
