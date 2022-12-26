package main
import "fmt"
func main()  {
    var a string
    a = "aaaa"
    a += "b"
    str := "love"
    fmt.Printf("%T\n",a)
    fmt.Println(a)
    fmt.Println(str)
    fmt.Println(len(a))
    fmt.Printf("str[0]:%c", str[0])
}
