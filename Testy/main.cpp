#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <cmath>
#include "sort.hpp"

int main()
{
    srand(time(NULL));

    int* tab = new int [SIZE];
    //int* extraArray = new int[SIZE];

    for(int i =0; i<SIZE;i++)
    {
        tab[i] = rand();
    }

    Sort sort;
    int n = sizeof(tab) / sizeof(tab);
    // pobierz maximum depth
	int maxdepth = log(n) * 2;

    Sort::showState(tab);
    Sort::introSort(tab,0,SIZE,maxdepth);
    //sort.mergeSort(tab,extraArray, 0, SIZE - 1);
    Sort::showState(tab);
    delete [] tab;
    //delete[] extraArray;

    return 0;
}