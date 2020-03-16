#ifndef test_hpp
#define test_hpp
#define SIZE 100
#include <cstdlib>
#include <ctime>
#include <iostream>


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

#endif