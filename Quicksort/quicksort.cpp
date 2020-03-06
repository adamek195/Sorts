#include "quicksort.hpp"

template<class T>
void showState(T data[])
{
    std::cout << "Our tables look like this: " << std::endl;
    for (int i=0; i<SIZE;i++)
    {
        std::cout <<i+1 <<"." << data[i] << std::endl; 
    }

}

template<class T>
void quickSort(T data[],int left,int right)
{
    int i,j,tmp,pivot; // zmienne potrzebne do obsugi algorytmu 

    i=(left+right)/2; //wyznaczamy pivot na środku
    pivot = data[i];
    data[i] = data[right]; // przesuwamy srodkowy element na koniec

    //wracamy na poczatek tablicy z indeksem
    for(j=i=left; i< right; i++)
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

    data[right] = data[j];
    data[j] = pivot;

    if(left < j-1)

        quickSort(data,left,j-1);
    if(j+1 < right)
        quickSort(data,j+1,right);
}



int main ()
{
    srand(time(NULL));

    int tab[SIZE];

    for(int i =0; i<SIZE;i++)
    {
        tab[i] = rand();
    }

    showState(tab);
    quickSort(tab,0,SIZE-1);
    showState(tab);
    return 0;
}