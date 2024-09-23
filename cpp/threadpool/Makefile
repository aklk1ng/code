tar = thread
CXXFLAGS = -g -O0 -Wall

all: $(tar)

$(tar): *.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

run:
	./$(tar)

.PHONY: clean

clean:
	rm $(tar)
