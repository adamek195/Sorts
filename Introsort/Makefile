all: main.o introsort.o
	g++ main.o introsort.o -o output
 
main.o: main.cpp
	g++ -c main.cpp
 
quicksort.o: introsort.cpp
	g++ -c introsort.cpp