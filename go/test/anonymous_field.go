package main

import "fmt"

type Person struct {
	id  int
	age int
}
type student struct {
	Person
	id int
}

func main() {
	s := student{Person: Person{id: 8, age: 19}, id: 20}
	fmt.Println(s)
	fmt.Printf("%+v", s)
}
