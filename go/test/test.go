package main

func main() {
	map1 := make(map[int]int)
	map1[1] = 1
	map1[2] = 2
	map1[3] = 3
	map1[4] = 4
	for key, value := range map1 {
		println(key, value)
	}
}
