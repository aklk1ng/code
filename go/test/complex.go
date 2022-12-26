package main
import "fmt"
func main()  {
    var t complex128
    t = 1+1i
    fmt.Printf("%T\n", t)
    fmt.Println(t)
    t1 := 3+1i
    fmt.Println(t1)
    fmt.Println("real(t1) = ", real(t1), "imag(t1)  = ", imag(t1))
}
