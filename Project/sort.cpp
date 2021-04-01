#include <math.h>
#include "sort.hpp"

/*podzielenie tablicy przez piwot tzw dziel i rzadz */
template<class T>
int Sort<T>::partitionArray(T data[], int leftIndex, int rightIndex)
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

/*implementacja algorytmu sortowania szybkiego*/
template<class T>
void Sort<T>::quickSort(T data[],int leftIndex,int rightIndex)
{
    /*sprawdzamy wyjatkowy przypadek */
    if(leftIndex >= rightIndex)
        return;

    int border = partitionArray(data, leftIndex, rightIndex);

    if(border - leftIndex < rightIndex - border)
    {
        quickSort(data, leftIndex, border - 1);
        quickSort(data, border + 1, rightIndex);
    }
    else
    {
         quickSort(data, border + 1, rightIndex);
         quickSort(data, leftIndex, border - 1);
    }
}

/*dzielenie tablicy na mniejsze podtablice*/
template<class T>
void Sort<T>::merge(T data[],T extraArray[], int leftIndex, int middleIndex, int rightIndex)
{
    /*wypelniamy elementami tablice pomocnicza */
    for (int i = leftIndex; i <= rightIndex; i++)
    {
        extraArray[i] = data[i];
    }

    int finger1 = leftIndex; // poczatkowy element wskazujacy na pierwszy element pierwszej podtablicy
    int finger2 = middleIndex + 1; // poczatkowy element wskazujacy na pierwszy element drugiej podtablicy
    int current = leftIndex; // obecny element ktory bedziemy przypisywac do sortowanej tablicy na poczatku indeks przypisany lewej

    /*petla while ktora bedzie dzialas az nie wyczerpia sie elementy obu podtablic bedzie kontynuowac scalanie */
    while (finger1 <= middleIndex && finger2 <= rightIndex)
    {
        /*wlasciwe sortowanie i wybieranie elementow */
        if (extraArray[finger1] <= extraArray[finger2])
        {
            data[current] = extraArray[finger1];
            finger1++; // jesli pobralismy element z pierwszej podtablicy to przesuwamy wskazujacy element
        }
        else
        {
            data[current] = extraArray[finger2];
            finger2++; // jesli pobralismy element z drugiej podtablicy to przesuwamy wskazujacy element
        }
        current++; //przesuwamy obecny element tablicy niezaleznie z jakiej podtablicy wzielismy
    }
    /*przypadek krytyczne gdy szybciej skonczy sie pierwsza lub druga podtablica w petli powyzej */
    while (finger1 <= middleIndex)
    {
        data[current] = extraArray[finger1];
        current++;
        finger1++;
    }
}


/*implementacja algorytmu przez scalanie*/
template<class T>
void Sort<T>::mergeSort(T data[],T extraArray[], int leftIndex, int rightIndex)
{
    //dzielimy problem na dwa mniejsze problemy(podzial tablicy na dwa)
    int middle;
    if (leftIndex < rightIndex)
    {
        middle = (leftIndex + rightIndex) / 2;
        //dwa mniejsze problemy sortujemy - rekurencja
        mergeSort(data,extraArray, leftIndex, middle);
        mergeSort(data,extraArray, middle + 1, rightIndex);
        //metoda scalujaca dwie posortowane juz tablice
        merge(data,extraArray, leftIndex, middle, rightIndex);
    }
}

/*wyznaczanie najwiekszej wartosci na gore kopca */
template<class T>
void Sort<T>::validateMaxHeap(T data[],int heapSize,int parentIndex)
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
template<class T>
void Sort<T>::heapSort(T data[],int length)
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

/*implementacja algorytmu sortowania przez wstawianie */
template<class T>
void Sort<T>::insertionSort(T *tab, int leftIndex, int rightIndex)
{
	for (int i = leftIndex + 1; i <= rightIndex; i++)
	{
		int key = tab[i];
		int j = i;

		while (j > leftIndex && tab[j - 1] > key)
        {
            tab[j] = tab[j - 1];
            j--;
        }
		tab[j] = key;
	}
}

/*implementacja algorytmu wstpenego sortowania introspektywnego */ 
template<class T>
void Sort<T>::introSortUtil(T data [],T *begin,T *end,int depthLimit)
{
    int size = end - begin;
    if (size < 16)
    {
        insertionSort(data,begin - data, end - data);
        return;
    }
    if(depthLimit == 0)
    {
        heapSort(data,size+1);
        return;
    }
    int pivot = partitionArray(data, begin - data, end - data);
    introSortUtil(data, begin , data + pivot-1, depthLimit-1);
    introSortUtil(data, data+pivot+1, end , depthLimit - 1);
}

/*implementacja algorytmu sortowania introspektywnego */
template<class T>
void Sort<T>::introSort(T data[],T *leftIndex,T *rightIndex)
{
    int depthLimit = 2 * log(rightIndex-leftIndex);
    introSortUtil(data,leftIndex,rightIndex,depthLimit);
    return;
}


//wyrażna deklaracja szablonu !!!
template class Sort<int>;