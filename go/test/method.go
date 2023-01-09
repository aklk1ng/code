package main

import "fmt"

func add(a,b int) int{
    return a + b
}

type long int
// bind a function to a type
// the receiver(tmp) is a passed parameter
func (tmp long) Add(other long) long {
    return tmp + other 
}
func test() {
    var result long = 2
    sum := result.Add(10)
    fmt.Println(sum)
}

type Person struct {
    name string
    id int
    age int
}
func (tmp Person) Print() {
    fmt.Println(tmp)
}
func (tmp *Person) print() {
    fmt.Println(tmp)
}
func test1() {
    p := new(Person) 
    point := new(Person)
    point.name = "ooo"
    point.id = 2
    point.age = 100
    p.name = "xxx"
    p.id = 1
    p.age = 20
    // method value
    // save the address of the method
    Fun := p.Print
    // hidden the receiver
    pFun := (*Person).Print
    Fun()
    pFun(point)
}

func main() {
    // test()
    test1()
}
