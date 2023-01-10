package main

import (
	"errors"
	"fmt"
)

type Humaner interface {
    sayhi()
}
type Personer interface {
    Humaner
    sing(name string)
}
type student struct {
    id int
    age int
}
func (tmp *student) sayhi() {
    fmt.Println(tmp)
}
func (tmp *student) sing(name string) {
    fmt.Println(name)
}
type teacher struct {
    id int
    age int
}
func (tmp *teacher) sayhi() {
    fmt.Println(tmp)
}
type Mystr string
func (tmp *Mystr) sayhi() {
    fmt.Println(*tmp)
}

// a ordinary function whose parameters are of type interface
// polymorphism
func WhoSayHi(i Humaner) {
    i.sayhi()
}

func test() {
    var i Humaner
    s := new(student)
    s.age = 10
    s.id = 1
    i = s
    i.sayhi()
    WhoSayHi(s)

    t := new(teacher)
    t.age = 19
    t.id = 3
    i = t
    i.sayhi()
    WhoSayHi(t)

    var st Mystr = "Hello interface"
    i = &st
    i.sayhi()
    WhoSayHi(&st)

    fmt.Printf("---------------------\n")

    x := make([]Humaner, 3, 10)
    x[0] = s
    x[1] = t
    x[2] = &st
    for _,value := range x{
        value.sayhi()
    }
}

func test2() {
    var i Personer
    s := new(student)
    i = s
    i.sayhi()
    i.sing("Hello")
}

func test3() {
    var iPro Personer
    iPro = &student{19, 0}
    var i Humaner
    i = iPro
    i.sayhi()
}
func test4() {
    // empty interface
    var i interface{}
    i = "abc"
    fmt.Println(i)
}
func test5() {
    i := make([]interface{}, 3)
    i[0] = 1
    i[1] = "abc"
    i[2] = student{13, 1}
    for index,value := range i{
        // the first return value is the data, the second return value is the judge result(true/false)
        if data, ok := value.(int); ok == true {
            fmt.Printf("%d--%d\n", index, data)
        } else if data, ok := value.(string); ok == true {
            fmt.Printf("%d--%s\n", index, data)
        } else if data, ok := value.(student); ok == true {
            fmt.Printf("%d--%d--%d\n", index, data.id, data.age)
        }
    }
}
func test6() {
    i := make([]interface{}, 3)
    i[0] = 1
    i[1] = "abc"
    i[2] = student{13, 1}
    for index, data := range i {
        switch value := data.(type) {
        case int:
            fmt.Printf("%d--%d\n", index, value)
        case string:
            fmt.Printf("%d--%s\n", index, value)
        case student:
            fmt.Printf("%d--%d--%d\n", index, value.id, value.age)
        }
    }
}
func test7() {
    err := fmt.Errorf("%s", "this is a normal error")
    fmt.Println(err)

    err1 := errors.New("this is a normal error1")
    fmt.Println(err1)
}

func main() {
    // test() 
    // test2()
    // test3()
    // test4()
    // test5()
    // test6()
    test7()
}
