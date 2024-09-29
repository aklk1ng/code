tar = ThreadPool
src = $(wildcard *.cpp)

all: $(tar)

$(tar): $(src) Makefile
	clang++ $< -o $@ -std=c++2a -pedantic

clean:
	rm $(tar)
