all: main.o quicksort.o
	g++ main.o quicksort.o -o output
 
main.o: main.cpp
	g++ -c main.cpp
 
quicksort.o: quicksort.cpp
	g++ -c quicksort.cpp
 
clean:
	rm *.o