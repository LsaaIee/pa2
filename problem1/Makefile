# Write your makefile here
all: fraction
fraction: fraction.o main.o
	g++ -W -Wall -o fraction fraction.o main.o
fraction.o: fraction.cc
	g++ -W -Wall -c -o fraction.o fraction.cc
main.o: main.cc 
	g++ -W -Wall -c -o main.o main.cc 
clean:
	rm -rf *.o fraction
