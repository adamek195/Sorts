#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <cmath>
#include "introsort.hpp"

template<typename T>
void showState(T data[])
{
    std::cout << "Our tables look like this: " << std::endl;
    for (int i=0; i<SIZE;i++)
    {
        std::cout <<i+1 <<"." << data[i] << std::endl; 
    }

}

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

/*sortowanie przez wstawanie*/
template<typename T>
void insertionSort (T data[], int length)
{
    /*zmienne potrzebne do obslugi algorytmu */
    int i, j;
    T tmp;
    for (i=1; i<length; i++)
    {
        tmp=data[i];
        for (j=i; j>0 && tmp<data[j-1]; j--)
            data[j]=data[j-1];

        data[j]=tmp;
    }
}

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

template<typename T>
void introSort( T data[], int firstIndex, int lastIndex, int maxDepth )
{
    if ( firstIndex < lastIndex )
    {
        if ( !maxDepth )
        {
            heapSort( data,lastIndex );
            return;
        }
        int border = partitionArray( data, firstIndex, lastIndex);
        introSort( data, firstIndex, border-1, maxDepth-1 );
        introSort( data, border+1, lastIndex, maxDepth-1 );
    }
}


int main()
{
    srand(time(NULL));

    int* tab = new int [SIZE];

    for(int i =0; i<SIZE;i++)
    {
        tab[i] = rand();
    }

    int n = sizeof(tab) / sizeof(tab);
    // pobierz maximum depth
	int maxdepth = log(n) * 2;

    showState(tab);
    introSort(tab,0,SIZE,maxdepth);
    showState(tab);
    delete [] tab;

    return 0;
}