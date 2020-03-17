#include <cmath>
#include <chrono>
#include <ratio>
#include "sort.hpp"
#include "test.hpp"

int main()
{
    int length;
    std::cout << "Podaj wilekosc: ";
    std::cin >> length;
    /*tworzymy wiersze*/
    int** tab = new int *[SIZE];
    /*tworzymy kolumny dynamicznie */
    for(int i = 0; i< SIZE;i++)
        tab[i] = new int[length];

    std::cout << "Podaj procent jaki ma byc tablicy posortowany: ";
    /*procent*/
    double perCent;
    std::cin >> perCent;
    std::cout << std::endl;    

    /*wypelniamy tablice randomowymi liczbami */
    fillAray_random(tab,length);
    showState(tab,length);
    for(int i=0; i < SIZE; i++)
        sortAray_percent(tab[i],length,perCent);
    showState(tab,length);

    /*czas przed sorotwaniem algorytmu */
    auto time_start = std::chrono::high_resolution_clock::now();
    for(int i = 0; i < SIZE; i++)
        Sort::quickSort(tab[i],0,length-1);    
    /*czas po sortowaniu algorytmu*/
    auto time_end = std::chrono::high_resolution_clock::now();

    /*czas trwania zmiennoprzecinkowego*/
    std::chrono::duration<double, std::milli> algorithmTime_ms = time_end - time_start;
 
    // integralny czas trwania: wymaga czasu duration_cast
    auto int_ms = std::chrono::duration_cast<std::chrono::milliseconds>(time_end - time_start);
 
    /* zamiana calkowiego czasu na mniejsza jednostke
    nie potrzebny duration_cast */
    std::chrono::duration<long, std::micro> int_usec = int_ms;

    std::cout << "algorithm took " << algorithmTime_ms.count() << " ms, "
              << "or " << int_ms.count() << " whole milliseconds "
              << "(which is " << int_usec.count() << " whole microseconds)" << std::endl;



    /*uswanie dynamicznie zaalokowanej tablicy */
    for (int i = 0; i<SIZE; i++)
        delete [] tab[i];
    delete [] tab;

    return 0;
}