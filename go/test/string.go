package main

import (
	"fmt"
	"strconv"
	"strings"
)

func test() {
	var a string
	a = "aaaa"
	a += "b"
	str := "love"
	fmt.Printf("%T\n", a)
	fmt.Println(a)
	fmt.Println(str)
	fmt.Println(len(a))
	fmt.Printf("str[0]:%c", str[0])
}
func test1() {
	fmt.Println(strings.Contains("hello go", "hello"))
}
func test2() {
	s := []string{"abc", "hello", "mike", "go"}
	buf := strings.Join(s, "@")
	fmt.Println(strings.Contains("hello go", "hello"))
	fmt.Println(buf)
}
func test3() {
	fmt.Println(strings.Index("abchello", "hello"))

	buf := strings.Repeat("go", 3)
	fmt.Println(buf)
}
func test4() {
	str := "hello@abc@go@mike"
	s := strings.Split(str, "@")
	fmt.Println(s)

	buf := strings.Trim("    test the function     ", " ")
	fmt.Println(buf)

	s2 := strings.Fields("   test the function     ")
	fmt.Println(s2)
	for _, value := range s2 {
		fmt.Println(value)
	}
}
func test5() {
	slice := make([]byte, 0, 1024)
	slice = strconv.AppendBool(slice, true)
	slice = strconv.AppendInt(slice, 1234, 10)
	slice = strconv.AppendQuote(slice, "abc")
	fmt.Println(string(slice))
}
func test6() {
	var str string
	str = strconv.FormatBool(false)
	str = strconv.FormatFloat(3.14, 'f', -1, 64)
	str = strconv.Itoa(6666)
	fmt.Println(str)
}
func test7() {
	var flag bool
	var err error
	flag, err = strconv.ParseBool("true")
	if err == nil {
		fmt.Println(flag)
	} else {
		fmt.Println(err)
	}

	a, _ := strconv.Atoi("567")
	fmt.Println(a)
}

func main() {
	// test()
	// test1()
	// test2()
	// test3()
	// test4()
	// test5()
	// test6()
	test7()
}
