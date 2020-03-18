#include <ctime>
#include <algorithm>
#include <cmath>
#include "introsort.hpp"
#include "introsort.cpp"

int main()
{
    srand(time(NULL));

    int* tab = new int [SIZE];

    for(int i =0; i<SIZE;i++)
    {
        tab[i] = rand();
    }

    int n = sizeof(tab) / sizeof(tab);
    std::cout << n << std::endl;
    // pobierz maximum depth
	int maxdepth = log(n) * 2;

    showState(tab);
    introSort(tab,0,SIZE,maxdepth);
    showState(tab);
    delete [] tab;

    return 0;
}