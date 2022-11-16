# Write your makefile here
all: calculator
calculator: calculator.o main.o
	g++ -W -Wall -o calculator calculator.o main.o
calculator.o: calculator.cc
	g++ -W -Wall -c -o calculator.o calculator.cc
main.o: main.cc 
	g++ -W -Wall -c -o main.o main.cc 
clean:
	rm -rf *.o calculator
