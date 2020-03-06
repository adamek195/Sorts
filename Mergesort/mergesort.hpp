#ifndef mergesort_hpp
#define mergesort_hpp
#include <iostream>
#include <cstdlib>
#include <ctime>
#define SIZE 1000


template<class T>
void mergeSort(T data[],int right, int left);

template<class T>
void showState(T data[]);
#endif