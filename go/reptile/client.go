package main

import (
	"fmt"
	"net/http"
	"os"
	"regexp"
	"strconv"
)

func HttpGet(url string) (result string, err error) {
	resp, err1 := http.Get(url)
	if err1 != nil {
		err = err1
		return
	}
	defer resp.Body.Close()

	buf := make([]byte, 1024*5)
	for {
		n, err := resp.Body.Read(buf)
		if n == 0 {
			fmt.Println("resp.Body.Read error", err)
			break
		}
		result += string(buf[:n])
	}
	return
}

func Reptile(i int, page chan<- int) {
	url := "https://tieba.baidu.com/f?kw=lol&ie=utf-8&pn=" + strconv.Itoa((i-1)*50)
	fmt.Printf("The %d page:%s", i, url)
	result, err := HttpGet(url)
	if err != nil {
		fmt.Println("HttpGet error", err)
		return
	}

	res := regexp.MustCompile(`<h1 class="dp-b"><a href="(?s:(.*?))"`)
	if res == nil {
		fmt.Println("regexp.MustCompile error")
		return
	}
	joyUrls := res.FindAllStringSubmatch(result, -1)
	fmt.Println(joyUrls)
	fileName := strconv.Itoa(i) + ".html"
	f, err1 := os.Create(fileName)
	if err1 != nil {
		fmt.Println("os.Create error", err1)
		return
	}
	f.WriteString(result)
	f.Close()
	page <- i
}

func Work(start, end int) {
	fmt.Printf("reptiling the pages\n")
	page := make(chan int)
	for i := start; i <= end; i++ {
		go Reptile(i, page)
	}
	for i := start; i <= end; i++ {
		fmt.Printf("The %d page is over\n", page)
	}
}

func main() {
	var start, end int
	fmt.Printf("Please enter the start page(>= 1):")
	fmt.Scan(&start)
	fmt.Printf("Please enter the end page(>= start page):")
	fmt.Scan(&end)

	Work(start, end)
}
