#ifndef quicksort_hpp
#define quicksort_hpp

template<typename T>
void heapSort(T data[],int length);

template<typename T>
void validateMaxHeap(T data[],int heapSize, int parentIndex);

template<typename T>
void showState(T data[]);
#endif