package main

import "fmt"

type student struct {
	id     int
	name   string
	sex    byte
	age    int
	adress string
}

func main() {
	var p *student
	var s student = student{1, "xxx", 'a', 19, "1fwsedf1"}
	s1 := student{name: "ooo", age: 20, adress: "1gdsff"}
	p = &s1
	p2 := &student{name: "ooo", age: 20, adress: "1gdsff"}
	point := new(student)
	point.adress = "sdf1"
	s.id = 2
	(*p2).id = 10
	p2.id = 1000
	fmt.Println(s)
	fmt.Println(s1)
	fmt.Println(*p)
	fmt.Println(*p2)
	fmt.Println(point)
}
package main

import "fmt"

type student struct {
	id     int
	name   string
	sex    byte
	age    int
	adress string
}

func main() {
	var p *student
	var s student = student{1, "xxx", 'a', 19, "1fwsedf1"}
	s1 := student{name: "ooo", age: 20, adress: "1gdsff"}
	p = &s1
	p2 := &student{name: "ooo", age: 20, adress: "1gdsff"}
	point := new(student)
	point.adress = "sdf1"
	s.id = 2
	(*p2).id = 10
	p2.id = 1000
	fmt.Println(s)
	fmt.Println(s1)
	fmt.Println(*p)
	fmt.Println(*p2)
	fmt.Println(point)
}
