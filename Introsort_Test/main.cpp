#include <ctime>
#include <algorithm>
#include <cmath>
#include "introsort.hpp"

int main()
{
    srand(time(NULL));

    int* tab = new int [SIZE];

    for(int i =0; i<SIZE;i++)
    {
        tab[i] = rand();
    }
    int maxdepth = log(SIZE) * 2;

    showState(tab);
    introSort(tab,tab,tab+SIZE-1);
    showState(tab);
    delete [] tab;

    return 0;
}