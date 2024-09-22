src = $(wildcard *.cpp)
tar = Speech_Contest

all: $(tar)

$(tar): $(src)
	$(CXX) $(src) -o $(tar)

.PHONY: clean
clean:
	rm $(tar)
