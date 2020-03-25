#ifndef sort_hpp
#define sort_hpp

template<typename T>
class Sort
{
    public:
    /*definicja funkcji ktora dzieli tablice wg piwota na dwie podtablice mniejsze i wieksze*/
    static int partitionArray(T data[], int leftIndex, int rightIndex);
    /*definicja algorytmu sorotwania szybkiego*/
    static void quickSort(T data[],int leftIndex,int rightIndex);
    /*dzielenie tablicy na mniejsze podtablice */
    static void merge(T data[],T extraArray[],int leftIndex,int middleIndex,int rightIndex);
    /*definicja algorytmu przez scalanie*/
    static void mergeSort(T data[],T extraArray[],int leftIndex, int rightIndex);
    /*wyzanczenie najwiekszej wartosci na gore kopca*/
    static void validateMaxHeap(T data[],int heapSize, int parentIndex);
    /*definicja algorytmu przez kopcowanie*/
    static void heapSort(T data[],int length);
    /*definicja algorytmu sortowanie przez wstawianie */
    static void insertionSort(T *tab, int leftIndex, int rightIndex);
    /*definicja wstepnej funkcji do sortowania introspektywnego */
    static void introSortUtil(T data[], T * begin, T * end, int depthLimit);    
    /*definicja algorytmu introspektywnego*/
    static void introSort(T data[], T *begin, T *end); 
};

#endif