package main

import (
	"fmt"
	"net/http"
)

func main() {
	// resp, err := http.Get("http://www.baidu.com")
	resp, err := http.Get("http://127.0.0.1:8000")
	if err != nil {
		fmt.Println(err)
		return
	}
	defer resp.Body.Close()
	fmt.Println(resp.Status)
	fmt.Println(resp.StatusCode)
	fmt.Println(resp.Header)
	buf := make([]byte, 4*1024)
	var tmp string
	for {
		n, _ := resp.Body.Read(buf)
		if n == 0 {
			break
		}
		tmp += string(buf)
	}
	fmt.Println(tmp)
}
