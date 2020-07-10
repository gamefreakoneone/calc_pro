all: hello
hello: main.o Calc.o
	g++ main.o Calc.o -o main
main.o: main.cpp
	g++ -c main.cpp
Calc.o: Calc.cpp
	g++ -c Calc.cpp
clean:
	rm -rf *o hello
