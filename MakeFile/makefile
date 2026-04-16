OBJS := $(patsubst %.cpp, %.o, $(wildcard *.cpp))

# 删掉也会自动推导main.o，会找到main.cpp进行编译
program : $(OBJS)
	g++ $(OBJS) -o program
main.o :
	g++ -c main.cpp -o main.o
hello.o :
	g++ -c hello.cpp -o hello.o
#

.PHONY : cleanAll cleanDiff cleanObj
cleanAll : cleanDiff cleanObj
	-rm -f program $(OBJS)
cleanDiff :
	echo "hello"
cleanObj :
	echo "YIKE"