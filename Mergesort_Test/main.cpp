#include <cstdlib>
#include <ctime>
#include "mergesort.hpp"

int main()
{
    srand(time(NULL));

    int* tab = new int[SIZE];
    int* extraArray = new int[SIZE];

    for (int i = 0; i < SIZE; i++)
    {
        tab[i] = rand();
    }
    showState(tab);
    mergeSort(tab,extraArray, 0, SIZE - 1);
    showState(tab);
    delete[] tab;
    delete[] extraArray;
    return 0;
}