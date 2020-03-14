all: main.o mergesort.o
	g++ main.o mergesort.o -o output
 
main.o: main.cpp
	g++ -c main.cpp
 
quicksort.o: mergesort.cpp
	g++ -c mergesort.cpp