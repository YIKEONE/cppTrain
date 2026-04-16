# Makefile

## 编译和链接
~~~bash
# 针对于编译器g++和语言cpp，通过-c 把cpp文件编译成.o文件
# -c 只编译不链接
# -o 输出目标文件
g++ -c hello.cpp -o hello.o
g++ -c main.cpp -o main.o
# 再链接
g++ main.o hello.o -o main
~~~



## 基本语法

#### 基本句式

~~~makefile
target : prerequisite1 prerequisite2
    commands
~~~

~~~bash

OBJS = main.o hello.o

# 删掉也会自动推导main.o，会找到main.cpp进行编译
program : $(OBJS)
	g++ $(OBJS) -o program
main.o :
	g++ -c main.cpp -o main.o
hello.o :
	g++ -c hello.cpp -o hello.o
#

.PHONY : clean
clean :
	rm -f program $(OBJS)

~~~

~~~bash
print.o speak.o : print.cpp speak.cpp
# 等同于
print.o : print.cpp speak.cpp
speak.o : print.cpp speak.cpp

# 如果必要条件太长了，可以
print.o : print.cpp speak.cpp
print.o : a.cpp b.cpp

# 如果文件有很多 且 要重复利用 可以定义一个变量

OBJ = a.o b.o \
    c.o

hello : $(OBJ)
    g++ hello -o $(OBJ)

# 看似无关的先决条件，但是其中有特性
vprint.o : lecxt.c
# 1. lecxt.c 被更新了， vprint.o就需要更新
# 2. vprint.o 更新前 lecxt.c 一定更新完了

# .PHONY 是一个伪目标, 他是目标 其的先决条件可以为清理 也可以为 整理之类的操作
.PHONY: clean
clean:
    rm -f *.o


~~~



#### 通配符

~~~makefile
# patsubst = pattern substitute 模板替换
# $(patsubst 原模式, 目标模式, 文本列表)
OBJS := $(patsubst %.cpp, %.o, $(wildcard *.cpp)) # wlidcard 匹配到所有的 .cpp 文件 ，patsubst把所有 .cpp 替换为 .o
~~~



#### 文件搜索

~~~makefile
# 定义VPATH了 make如果在当前目录找不到目标文件，就回去VPATH的目录下去寻找文件， 使用 : 分隔
VPATH = src : ../header

# vpath 则是make的关键字, 在当前目录下找所有cpp文件，找不到则去../srcs目录下找
vpath %.cpp ../srcs

# 当有相同的pattern时，就按照先后顺序查找，现在foo之后再blish最后在bar目录下找所有.c文件
vpath %.c foo
vpath %   blish
vpath %.c bar

vpath %.c foo : blish
vpath % bar
~~~



#### 伪目标

~~~makefile
# 伪目标也可以成为依赖, 类似于子程序
.PHONY : cleanall cleanobj cleandiff
cleanall : cleanobj cleandiff # 所以执行cleanall 前都cleanobj和cleandiff也都必须执行，也可以单独执行
    rm program
cleanobj :
    rm *.o
cleandiff :
    rm *.diff
~~~

