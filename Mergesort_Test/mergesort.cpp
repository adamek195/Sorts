#include "mergesort.hpp"
#include <iostream>

template<typename T>
void showState(T data[] )
{
    std::cout << "Our tables look like this: " << std::endl;
    for (int i = 0; i < SIZE; i++)
    {
        std::cout << i + 1 << "." << data[i] << std::endl;
    }
}

template<typename T>
void merge(T data[],T extraArray[], int leftIndex, int middleIndex, int rightIndex)
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


template<typename T>
void mergeSort(T data[],T extraArray[], int leftIndex, int rightIndex)
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
