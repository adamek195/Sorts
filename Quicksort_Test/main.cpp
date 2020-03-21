#include <cstdlib>
#include <ctime>
#include "quicksort.hpp"
#include "quicksort.cpp"

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