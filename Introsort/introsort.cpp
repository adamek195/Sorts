#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <cmath>
#include "introsort.hpp"


/*funkcja wypisujaca tablice */
template<typename T>
void showState(T data[])
{
    std::cout << "Our tables look like this: " << std::endl;
    for (int i=0; i<SIZE;i++)
    {
        std::cout <<i+1 <<"." << data[i] << std::endl; 
    }

}

/*wyznaczanie najwiekszej wartosci na gore kopca */
template<typename T>
void validateMaxHeap(T data[],int heapSize,int parentIndex)
{
    T tmp;
    /*przypisujemy rodzicowi i dziecią kolejno odpowiednie indeksy wg wzoru */
    int maxIndex = parentIndex;
    int leftChild = parentIndex*2+1;
    int rightChild = parentIndex*2+2;

    /*jesli dziecko wieksze od rodzica to zmieniamy indeksy, najpierw sprawdz lewe potem prawe dziecko */
    if(leftChild < heapSize && data[leftChild] > data[maxIndex])
        maxIndex = leftChild;

    if(rightChild < heapSize && data[rightChild] > data[maxIndex])
        maxIndex = rightChild;

    /*jesli maxIndex zmienil indeks to zamieniami z dzieckiem warosci*/
    if( maxIndex != parentIndex)
    {
        tmp = data[maxIndex];
        data[maxIndex] = data[parentIndex];
        data[parentIndex] = tmp;
        /*sprawdzamy rekurencyjnie czy rodzic po zamianie jest w odpowiedniej pozycji */
        validateMaxHeap(data, heapSize, maxIndex);
    }      
}

/*sortowanie przez kopcowanie*/
template<typename T>
void heapSort(T data[],int length)
{
    T tmp;
    /*ustawienie najwiekszej wartosci na gorze kopca */
    for(int i = length/2-1; i >= 0; i--)
    {
        validateMaxHeap(data,length,i);
    }

    /*zamiana pierwszego elementu z ostatnim i rekurencyjnie ustawinie najwiekszego elementu na gorze kopca */
    for(int i = length-1; i > 0 ; i--)
    {
        tmp = data[i];
        data[i] = data[0];
        data[0] = tmp;
        length--;
        validateMaxHeap(data,length,0);
    }
}

/*funckja wymieniajaca dwa elementy tablicy wg indeksu potrzebna do introSorta*/
template<typename T>
void swapValue_Intro(T *a, T *b) 
{ 
    T *temp = a; 
    a = b; 
    b = temp; 
    return; 
} 


/*sortowanie przez wstawanie*/
template<typename T>
void InsertionSort_Intro(T data[], int *begin, int *end) 
{ 
    /*Pobierz lewy i prawy indeks tablicy cząstkowej do posortowania*/
    int leftIndex = begin - data; 
    int rightIndex = end - data; 
  
    for (int i = leftIndex+1; i <= rightIndex; i++) 
    { 
        int key = data[i]; 
        int j = i-1; 
  
       /* Przesunąć elementy tablicy, które są większe od klucza,
       na jedną pozycję przed ich aktualną pozycją*/
        while (j >= leftIndex && data[j] > key) 
        { 
            data[j+1] = data[j]; 
            j = j-1; 
        } 
        data[j+1] = key; 
   } 
  
   return; 
} 

/*Funkcja umożliwiająca partycjonowanie tablicy i zwrócenie punktu partycji*/
template<typename T>
int* Partition_Intro(T data[], int low, int high) 
{ 
    /*pivot*/
    int pivot = data[high];    
    /*Indeks mniejszego elementu*/ 
    int i = (low - 1);
    /*zmienna tymczasowa */ 
    T tmp;
    for (int j = low; j <= high- 1; j++) 
    { 
        /*Jeśli aktualny element jest mniejszy lub równy wychyleniu*/
        if (data[j] <= pivot) 
        { 
            /*zwiekszaj o 1 indeks elementu mniejszego*/ 
            i++; 
            tmp =  data[i];
            data[i] = data[j];
            data[j] = tmp;
        } 
    } 
    tmp =  data[i + 1];
    data[i + 1] = data[high];
    data[high] = tmp; 
    return (data + i + 1); 
} 

/*Funkcja, która znajduje środek wartości wskazywanych
przez wskaźniki a, b, c i zwraca ten wskaznik*/
int *MedianOfThree(int * a, int * b, int * c) 
{ 
    if (*a < *b && *b < *c) 
        return (b); 
  
    if (*a < *c && *c <= *b) 
        return (c); 
  
    if (*b <= *a && *a < *c) 
        return (a); 
  
    if (*b < *c && *c <= *a) 
        return (c); 
  
    if (*c <= *a && *a < *b) 
        return (a); 
  
    if (*c <= *b && *b <= *a) 
        return (b); 
} 


/*IntroSort  wykonywanie wstępne*/
template<typename T>
void IntrosortUtil(T data[], T * begin, T * end, int depthLimit) 
{ 
    /*Policz liczbe elementow */
    int size = end - begin; 
  
      /* jesli dlugosc jest mniejsza zrob sortowanie przez wstawianie*/ 
    if (size < 16) 
    { 
        InsertionSort_Intro(data, begin, end); 
        return; 
    } 
  
    /* Jesli glebokosc wynienie 0 uzyj heapSort*/
    if (depthLimit == 0) 
    { 
        heapSort(begin,size+1);
        return; 
    } 
  
    /*uzyj mediany trzech elementow zeby znalezc dobry pivot*/
    int * pivot = MedianOfThree(begin, begin+size/2, end); 
  
    /* zamien pivot z koncowym elementem*/
    swapValue_Intro(pivot, end); 
  
   /* podziel jak w  Quick Sort*/ 
    int * partitionPoint = Partition_Intro(data, begin-data, end-data); 
    IntrosortUtil(data, begin, partitionPoint-1, depthLimit - 1); 
    IntrosortUtil(data, partitionPoint + 1, end, depthLimit - 1); 
  
    return; 
} 


/* Implementacja sortowania introspektywnego*/
void introSort(int data[], int *begin, int *end) 
{ 
    int depthLimit = 2 * log(end-begin); 
  
    // Perform a recursive Introsort 
    IntrosortUtil(data, begin, end, depthLimit); 
  
      return; 
} 


/*podzielenie tablicy przez piwot tzw dziel i rzadz */
template<typename T>
int partitionArray(T data[], int leftIndex, int rightIndex)
{
    /*zmienna potrzebna do obslugi algorytmu*/
    T tmp;
    /*ustawiamy pivot na srodku */
    int pivotIndex = leftIndex + (rightIndex - leftIndex)/2;
    
    /*srodkowa wartosc przesuwamy na ostatni element tablicy zeby mozna bylo porownac z kazdym elementem */
    T pivotValue = data[pivotIndex];
    tmp = data[pivotIndex];
    data[pivotIndex] = data[rightIndex];
    data[rightIndex] = tmp;
    /*zmienne potrzebne do przejscia po elementach tablicy i wyznaczeniu granicy*/
    int border = leftIndex - 1;
    int i = leftIndex;

    /*petla przechodzaca po tablicy i porownujaca elementy z pivotem oraz wyznaczajaca grancie */
    while(i < rightIndex)
    {
        if(data[i] < pivotValue)
        {
            border++;
            if(border != i)
            {
                tmp = data[i];
                data[i] = data[border];
                data[border] = tmp;
            }
        }
        /*zwiekszamy iteracje */
        i++;
    }
    /*sprawdzamy przypadek gdyby granica nie byla na koncu tablicy*/
    border++;
    if(border != rightIndex)
    {
        tmp = data[rightIndex];
        data[rightIndex] = data[border];
        data[border] = tmp;
    }
    return border;
}

/*template<typename T>
void introSort(T data[], int firstIndex,int lastIndex, int maxDepth)
{
    if(!maxDepth)
    {
        int length = lastIndex - firstIndex + 1;
        heapSort(data,lastIndex);
        return;
    }
    else
    {
        int border = partitionArray( data, firstIndex, lastIndex);
        introSort( data, firstIndex, border-1, maxDepth-1 );
        introSort( data, border+1, lastIndex, maxDepth-1 );
    }
}*/
