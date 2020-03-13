#include "quicksort.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

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
void quickSort(T data[],int leftIndex,int rightIndex)
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




int main ()
{
    srand(time(NULL));

    int* tab = new int [SIZE];

    for(int i =0; i<SIZE;i++)
    {
        tab[i] = rand();
    }

    showState(tab);
    /*tu musi byc ta jedynka*/
    quickSort(tab,0,SIZE-1);
    showState(tab);
    delete [] tab;
    return 0;
}