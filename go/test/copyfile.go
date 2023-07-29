package main

import (
	"fmt"
	"io"
	"os"
)

func test() {
	list := os.Args
	if len(list) != 3 {
		fmt.Println("The usage isn't right")
		return
	}
	srcFile := list[1]
	dstFile := list[2]
	if srcFile == dstFile {
		fmt.Println("The file names are same")
		return
	}

	sF, err1 := os.Open(srcFile)
	if err1 != nil {
		fmt.Println(err1)
		return
	}
	dF, err2 := os.Create(dstFile)
	if err2 != nil {
		fmt.Println(err2)
		return
	}
	defer sF.Close()
	defer dF.Close()

	buf := make([]byte, 1024*4)
	for {
		n, err := sF.Read(buf)
		if err != nil {
			if err == io.EOF {
				break
			}
			fmt.Println(err)
		}
		dF.Write(buf[:n])
	}
}

func main() {
	test()
}
