package main

import (
	"encoding/json"
	"fmt"
)

type IT struct {
    Company string `json:"company"`
    Subjects []string `json:"subjects"`
    IsOk bool `json:",string"`
    Price float64 `json:"price"`
}
func test1() {
    s := IT{"itcast", []string{"Go", "Cpp", "Rust"}, true, 888.000}
    // buf, err := json.Marshal(s)
    buf, err := json.MarshalIndent(s, "", " ")
    if err != nil {
        fmt.Println(err)
        return
    }
    fmt.Println(string(buf))
}
func test2() {
    m := make(map[string]interface{}, 4)
    m["Company"] = "itcast"
    m["subjects"] = []string{"Go", "Cpp", "Rust"}
    m["IsOk"] = true
    m["price"] = 888.000
    buf, err := json.MarshalIndent(m, "", " ")
    if err != nil {
        fmt.Println(err)
        return
    }
    fmt.Println(string(buf))
}
func test3() {
    jsonBuf := `
    {
    "company": "itcast",
    "subjects": [
    "Go",
    "Cpp",
    "Rust"
    ]
    "isOk": "true",
    "price": 888.000,
    }
    `
    var tmp IT
    err := json.Unmarshal([]byte(jsonBuf), &tmp)
    if err != nil {
        fmt.Println(err)
        return
    }
    fmt.Println(tmp)
}
func test4() {
    jsonBuf := `    
    {
    "Company": "itcast",
    "IsOk": true,
    "price": 888,
    "subjects": [
    "Go",
    "Cpp",
    "Rust"
    ]
    }
    `
    m := make(map[string]interface{}, 4)
    err := json.Unmarshal([]byte(jsonBuf), &m)
    if err != nil {
        fmt.Println(err)
        return
    }
    fmt.Println(m)

    for key, value := range m{
        switch data := value.(type) {
        case string:
            fmt.Println(key, data)
        case bool:
            fmt.Printf(key, data)
        case float64:
            fmt.Println(key,data)
        case []interface{}:
            fmt.Println(key,data)
        }
    }
}

func main() {
    // test1()
    // test2()
    // test3()
    test4()
}
