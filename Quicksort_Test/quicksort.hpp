#ifndef quicksort_hpp
#define quicksort_hpp
#include <iostream>
#include <cstdlib>
#include <ctime>
#define SIZE 1000

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
void quickSort(T data[],int leftIndex,int rightIndex)
{
    int i,j;
    T tmp,pivot; // zmienne potrzebne do obsugi algorytmu 

    i=(leftIndex+rightIndex)/2; //wyznaczamy pivot na środku
    pivot = data[i];
    data[i] = data[rightIndex]; // przesuwamy srodkowy element na koniec

    //wracamy na poczatek tablicy z indeksem
    for(j=i=leftIndex; i< rightIndex; i++)
    {
        //spradzamy czy elementy sa mniejsze od piwota
        if(data[i]<pivot)
        {
            //elementy mniejsze zamieniamy elementy idenksow i z elementami indeksow j
            tmp = data[i];
            data[i] = data[j];
            data[j] = tmp;
            j++;
        }
    }

    data[rightIndex] = data[j];
    data[j] = pivot;

    if(leftIndex < j-1)
        quickSort(data,leftIndex,j-1);
    if(j+1 < rightIndex)
        quickSort(data,j+1,rightIndex);
}

#endif