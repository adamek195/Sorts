#ifndef quicksort_hpp
#define quicksort_hpp
#define SIZE 10

template<typename T>
void heapSort(T data[],int length);

template<typename T>
void validateMaxHeap(T data[],int heapSize, int parentIndex);

template<typename T>
void insertionSort (T data[], int length);

template<typename T>
void showState(T data[]);

template<typename T>
void introSort( T data[], int firstIndex, int lastIndex, int maxDepth );

template<typename T>
int partitionArray(T data[], int leftIndex, int rightIndex);

#endif