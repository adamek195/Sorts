#ifndef quicksort_hpp
#define quicksort_hpp
#include <iostream>
#include <cstdlib>
#include <ctime>
#define SIZE 500000


template<class T>
void quickSort(T data[],int right, int left);

template<class T>
void showState(T data[]);
#endif