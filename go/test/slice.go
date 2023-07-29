package main

import (
	"fmt"
)

func test1() {
	array := [5]int{1, 2, 3}
	//            [low:high:max]
	//            len = high - low
	//            capacity = max - low
	slice := array[0:2:5]
	s := make([]int, 3, 5)
	fmt.Println(slice)
	fmt.Println(len(slice))
	fmt.Println(cap(slice))
	fmt.Println(s)
}
func test2() {
	slice := []int{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10}
	s1 := slice[:]
	fmt.Println(s1, len(s1), cap(s1))
	s1 = append(s1, 200)
	fmt.Println(s1, len(s1), cap(s1))
	s2 := slice[:5]
	fmt.Println(s2, len(s2), cap(s2))
	s3 := slice[2:6]
	fmt.Println(s3, len(s3), cap(s3))
	s4 := slice[1:]
	fmt.Println(s4, len(s4), cap(s4))
	s4 = append(s4, 100)
	fmt.Println(s4, len(s4), cap(s4))
}
func test3() {
	slice := []int{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10}
	s1 := slice[2:6]
	fmt.Println(s1, len(s1), cap(s1))
	s2 := s1[3:]
	fmt.Println(s2, len(s2), cap(s2))
	s3 := s2[1:]
	fmt.Println(s3, len(s3), cap(s3))
	s3 = append(s3, 1)
	fmt.Println(s3, len(s3), cap(s3))

}
func main() {
	// test1()
	// test2()
	test3()
}
