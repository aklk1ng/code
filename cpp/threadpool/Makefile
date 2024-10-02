tar = thread
CXXFLAGS = -g -O0 -Wall
src = $(wildcard *.cpp)

all: $(tar)

$(tar): $(src) Makefile
	$(CXX) $(CXXFLAGS) $< -o $@

run:
	./$(tar)

.PHONY: clean

clean:
	rm $(tar)
