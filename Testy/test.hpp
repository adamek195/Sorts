#ifndef test_hpp
#define test_hpp
#define SIZE 100
#include <ctime>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include "sort.hpp"

/*funkcja wypisujaca tablice */
template<typename T>
void showState(T **data, int length)
{
    std::cout << "Our tables look like this: " << std::endl;
    for (int j=0; j<SIZE;j++)
    {
        std::cout << std::endl << j+1 << "."; 
        for(int i = 0; i<length; i++)
            std::cout << data[j][i] << " ";
    }
    std::cout << std::endl;
}

/*funkcja wypelniajaca tablice */
template<typename T>
void fillAray_random(T **data,int length)
{
    srand(time(NULL));

    for(int j =0; j < SIZE; j++)
        for(int i = 0; i <length; i++)
            data[j][i] = rand();
}

/*funkcja odwracajaca tablice ale jednowymiarowa */
template<typename T>
void fillAray_reverse(T *data,int length)
{
    for (int low = 0, high = length - 1; low < high; low++, high--)
		std::swap(data[low], data[high]);
}

/*funkcja sortujaca tablice dla poszczegolnego procenta */
template<typename T>
void sortAray_percent(T *data,int length,double perCent)
{
    srand(time(NULL));
    /*dlugosc tablicy ktorej procent chcemy posortowac */
    int lengthPercent = perCent*length;
     /*w celu posortowania tablicy uzyjemy algorytmu quicksort ktory jest najszybszy */
    Sort::quickSort(data,0,lengthPercent-1);
    for(int i = lengthPercent-1; i < length; i++)
    {
        if(data[i] < data[lengthPercent-1])
        {
            /*losuj dopoki elementy drugiej tablicy beda tylko wieksze od ostatniego elemntu podtablicy posortowanej */
           
            data[i] = rand()+data[lengthPercent-1];
        }    
    }  
}


/*funkcja sortujaca tablice dla poszczegolnego procenta pierwsza wersja zajmuje duzo pamieci*/
template<typename T>
void sortAray_percentSecond(T *data,int length,double perCent)
{
    /*dlugosc tablicy ktorej procent chcemy posortowac */
    int lengthPercent = perCent*length;

    /*tworzymy tablice tymczasowa */
    T* tmp = new T [lengthPercent];
    for(int i = 0; i  < lengthPercent; i++)
        tmp[i] = data[i];  
    /*w celu posortowania tablicy uzyjemy algorytmu quicksort ktory jest najszybszy */
    Sort::quickSort(tmp,0,lengthPercent-1);  
    /*posrtowane czesc tablicy przypisze sie calej tablicy */
    for(int i = 0 ; i < lengthPercent; i++)
        data[i] = tmp[i];  

    /*zwalaniamy tablice */
    delete [] tmp;    
}

#endif