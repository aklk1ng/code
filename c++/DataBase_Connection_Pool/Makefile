
src=$(wildcard *.cpp)
obj=$(patsubst %.cpp, %.o, $(src))
target=DataBase_Connection_Pool
$(target):$(src)
	$(CXX) $(src) -lmysqlclient -ljsoncpp -o $(target)
