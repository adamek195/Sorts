#ifndef mergesort_hpp
#define mergesort_hpp
#include <iostream>
#include <cstdlib>
#include <ctime>
#define SIZE 10


template<typename T>
void mergeSort(T data[],T extraArray[],int leftIndex, int rightIndex);

template<typename T>
void merge(T data[],T extraArray[],int leftIndex,int middleIndex,int rightIndex);

template<typename T>
void showState(T data[]);
#endif