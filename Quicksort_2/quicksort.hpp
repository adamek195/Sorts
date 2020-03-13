#ifndef quicksort_hpp
#define quicksort_hpp
#define SIZE 1000

template<typename T>
int partitionArray(T data[], int leftIndex, int rightIndex);

template<typename T>
void quickSort(T data[],int leftIndex,int rightIndex);

template<typename T>
void showState(T data[]);
#endif