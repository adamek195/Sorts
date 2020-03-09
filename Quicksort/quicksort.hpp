#ifndef quicksort_hpp
#define quicksort_hpp
#include <iostream>
#include <cstdlib>
#include <ctime>
#define SIZE 10


template<typename T>
void quickSort(T data[],int leftIndex,int rightIndex);

template<typename T>
void showState(T data[]);
#endif