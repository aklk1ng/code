src=$(wildcard *.cpp)
obj=$(patsubst %.cpp, %.o, $(src))
tar=Speech_Contest
$(tar):$(obj)
	$(CXX) $(obj) -o $(tar)
.PHONY:clean
clean:
	rm $(obj)
