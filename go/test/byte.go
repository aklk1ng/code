package main
import "fmt"
func main()  {
    var a byte
    a = 'a'
    fmt.Printf("a type:%T\n",a)
    fmt.Printf("a=%c  %d\n", a, a)
    // fmt.Println(a)
    fmt.Printf("%c\n", a-32)
}
