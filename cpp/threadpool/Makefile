tar = thread

all: $(tar)

$(tar): *.cpp
	$(CXX) -Wall $^ -o $@

run:
	./$(tar)

.PHONY: clean

clean:
	rm $(tar)
