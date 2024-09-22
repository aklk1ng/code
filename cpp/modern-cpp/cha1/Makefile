CXX = clang++
LDFLAGS_COMMON = -std=c++2a
TAR = main
SOURCE_C = foo.c
OBJECT_C = foo.o
SOURCE_CPP = main.cpp

all: $(TAR)

$(TAR): $(OBJECT_C) $(SOURCE_CPP)
	$(CC) -c $(SOURCE_C) -o $(OBJECT_C)
	$(CXX) $^ $(LDFLAGS_COMMON) -o $@

.PHONY: clean

clean:
	rm -rf *.o $(TAR);
