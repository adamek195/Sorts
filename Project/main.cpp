#include <cmath>
#include <chrono>
#include <ratio>
#include "sort.hpp"
#include "test.hpp"

int main()
{
    /*dynamicznie alokujemy pamiec dla konkretnej dlugosci tablicy*/
    int length;
    std::cout << "Podaj wielkosc: ";
    std::cin >> length;
    std::cin.ignore(100000,'\n');
    /*tworzymy wiersze*/
    int** tab = new int *[SIZE];
    /*tworzymy kolumny dynamicznie */
    for(int i = 0; i < SIZE;i++)
        tab[i] = new int[length];


    /*tworzymy menu do wybierania konkretnej tablicy*/
    int choice_array = 0;
    std::cout << "Wybierz rodzaj tablicy ktora chcesz posorotowac: " << std::endl;
    std::cout << "1. Tablica losowa: " << std::endl;
    std::cout << "2. Tablica ktorej czesc jest juz posortowana: " << std::endl;
    std::cout << "3. Tablica posorotwana w odwortnej kolejnosci: " << std::endl;
    std::cout << "4. Zamyka menu." << std::endl;
    std::cout << "Twoj wybor to : ";
    std::cin >> choice_array;
    std::cin.ignore(100000,'\n');
    switch(choice_array)
    {
        case 1:
        {
            fillAray_random(tab,length);
            break;
        }
        case 2:
        {
            std::cout << "Podaj procent jaki ma byc tablicy posortowany: ";
            /*procent*/
            double perCent;
            std::cin >> perCent;
            std::cin.ignore(100000,'\n');
            std::cout << std::endl;    
            /*wypelniamy tablice losowymi liczbami */
            fillAray_random(tab,length);
            /*sortujemy tablice pod wskazany procent */
            for(int i = 0; i < SIZE; i++)
                sortAray_percent(tab[i],length,perCent);
            break;    
        }
        case 3:
        {
            /*wypelniamy tablice randomowymi liczbami */
            fillAray_random(tab,length);
            /*Najpierw ja sortujemy */
            for(int i = 0; i < SIZE; i++)
                Sort<int>::quickSort(tab[i],0,length-1);
            /*Posortowana tablice odwracamy*/    
            for(int i = 0; i < SIZE; i++)    
                fillAray_reverse(tab[i],length);    
            break;       
        }
        case 4:
        {
            break;
        }
        default:
        {
            std::cout << "Nie ma takiej opcji w menu: " << std::endl;
        }
    }

    /*tworzymy zmienna do obslugi menu wyboru algorytmu */
    int choice_algorithm = 0;
    std::cout << "Wybierz algorytm ktory chcesz testowac: " << std::endl;
    std::cout << "1. Alogrytm sorotwania szybkiego: " << std::endl;
    std::cout << "2. Algorytm sorotwania przez scalanie: " << std::endl;
    std::cout << "3. Algorytm sortowania introspektywnego: " << std::endl;
    std::cout << "4. Zamyka menu." << std::endl;
    std::cout << "Twoj wybor to: ";
    std::cin >> choice_algorithm;
    std::cin.ignore(100000,'\n');
    switch(choice_algorithm)
    {
        /*obslugujacy algorytm quicksort*/
        case 1:
        {
            /*czas przed sorotwaniem algorytmu */
            auto time_start = std::chrono::high_resolution_clock::now();
            for(int i = 0; i < SIZE; i++)
                Sort<int>::quickSort(tab[i],0,length-1);
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

            break;    
        }
        case 2:
        {
            int* extraArray = new int[length];
            /*czas przed sorotwaniem algorytmu */
            auto time_start = std::chrono::high_resolution_clock::now();
            for(int i = 0; i < SIZE; i++)
                Sort<int>::mergeSort(tab[i],extraArray,0,length-1);
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


            delete[] extraArray;
            break;
        }
        case 3:
        {
            /*czas przed sorotwaniem algorytmu */
            auto time_start = std::chrono::high_resolution_clock::now();
             for(int i = 0; i < SIZE; i++)
             {
               Sort<int>::introSort(tab[i], tab[i], tab[i]+length-1); 
             }
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
    
            break;
        }
        case 4:
        {
            break;
        }
        default:
        {
            std::cout << "Nie ma takiej opcji w menu: " << std::endl;
            break;
        }
    }    
    

    /*uswanie dynamicznie zaalokowanej tablicy */
    for (int i = 0; i<SIZE; i++)
        delete [] tab[i];
    delete [] tab;

    return 0;
}

