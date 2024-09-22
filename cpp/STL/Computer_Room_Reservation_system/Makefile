src = $(wildcard *.cpp)
target = Computer_Room_Reservation

all: $(target)

$(target): $(src)
	$(CXX) $(src) -o $(target)

.PHONY: clean
clean:
	rm $(target)
