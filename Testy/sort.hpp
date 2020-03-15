#ifndef quicksort_hpp
#define quicksort_hpp
#define SIZE 1000

class Sort
{
    public:
    /*definicja funkcji wypisujaca tablice */
    template<typename T>
    static void showState(T data[]);
    /*definicja funkcji ktora dzieli tablice wg piwota na dwie podtablice mniejsze i wieksze*/
    template<typename T>
    static int partitionArray(T data[], int leftIndex, int rightIndex);
    /*definicja algorytmu sorotwania szybkiego*/
    template<typename T>
    static void quickSort(T data[],int leftIndex,int rightIndex);
    /*dzielenie tablicy na mniejsze podtablice */
    template<typename T>
    static void merge(T data[],T extraArray[],int leftIndex,int middleIndex,int rightIndex);
    /*definicja algorytmu przez scalanie*/
    template<typename T>
    static void mergeSort(T data[],T extraArray[],int leftIndex, int rightIndex);
    /*wyzanczenie najwiekszej wartosci na gore kopca*/
    template<typename T>
    static void validateMaxHeap(T data[],int heapSize, int parentIndex);
    /*definicja algorytmu przez kopcowanie*/
    template<typename T>
    static void heapSort(T data[],int length);
    /*definicja algorytmu introspektywnego*/
    template<typename T>
    static void introSort( T data[], int firstIndex, int lastIndex, int maxDepth );
    /*definicja algorytmu przez wstawianie*/
    template<typename T>
    static void insertionSort (T data[], int length);
};




/*funkcja wypisujaca tablice */
template<typename T>
void Sort::showState(T data[])
{
    std::cout << "Our tables look like this: " << std::endl;
    for (int i=0; i<SIZE;i++)
    {
        std::cout <<i+1 <<"." << data[i] << std::endl; 
    }

}

/*podzielenie tablicy przez piwot tzw dziel i rzadz */
template<typename T>
int Sort::partitionArray(T data[], int leftIndex, int rightIndex)
{
    /*zmienna potrzebna do obslugi algorytmu*/
    T tmp;
    /*ustawiamy pivot na srodku */
    int pivotIndex = leftIndex + (rightIndex - leftIndex)/2;
    
    /*srodkowa wartosc przesuwamy na ostatni element tablicy zeby mozna bylo porownac z kazdym elementem */
    T pivotValue = data[pivotIndex];
    tmp = data[pivotIndex];
    data[pivotIndex] = data[rightIndex];
    data[rightIndex] = tmp;
    /*zmienne potrzebne do przejscia po elementach tablicy i wyznaczeniu granicy*/
    int border = leftIndex - 1;
    int i = leftIndex;

    /*petla przechodzaca po tablicy i porownujaca elementy z pivotem oraz wyznaczajaca grancie */
    while(i < rightIndex)
    {
        if(data[i] < pivotValue)
        {
            border++;
            if(border != i)
            {
                tmp = data[i];
                data[i] = data[border];
                data[border] = tmp;
            }
        }
        /*zwiekszamy iteracje */
        i++;
    }
    /*sprawdzamy przypadek gdyby granica nie byla na koncu tablicy*/
    border++;
    if(border != rightIndex)
    {
        tmp = data[rightIndex];
        data[rightIndex] = data[border];
        data[border] = tmp;
    }
    return border;
}

/*implementacja algorytmu sortowania szybkiego*/
template<typename T>
void Sort::quickSort(T data[],int leftIndex,int rightIndex)
{
    /*sprawdzamy wyjatkowy przypadek */
    if(leftIndex >= rightIndex)
        return;

    int border = partitionArray(data, leftIndex, rightIndex);

    if(border - leftIndex < rightIndex - border)
    {
        quickSort(data, leftIndex, border - 1);
        quickSort(data, border + 1, rightIndex);
    }
    else
    {
         quickSort(data, border + 1, rightIndex);
         quickSort(data, leftIndex, border - 1);
    }
}

/*dzielenie tablicy na mniejsze podtablice*/
template<typename T>
void Sort::merge(T data[],T extraArray[], int leftIndex, int middleIndex, int rightIndex)
{
    /*wypelniamy elementami tablice pomocnicza */
    for (int i = leftIndex; i <= rightIndex; i++)
    {
        extraArray[i] = data[i];
    }

    int finger1 = leftIndex; // poczatkowy element wskazujacy na pierwszy element pierwszej podtablicy
    int finger2 = middleIndex + 1; // poczatkowy element wskazujacy na pierwszy element drugiej podtablicy
    int current = leftIndex; // obecny element ktory bedziemy przypisywac do sortowanej tablicy na poczatku indeks przypisany lewej

    /*petla while ktora bedzie dzialas az nie wyczerpia sie elementy obu podtablic bedzie kontynuowac scalanie */
    while (finger1 <= middleIndex && finger2 <= rightIndex)
    {
        /*wlasciwe sortowanie i wybieranie elementow */
        if (extraArray[finger1] <= extraArray[finger2])
        {
            data[current] = extraArray[finger1];
            finger1++; // jesli pobralismy element z pierwszej podtablicy to przesuwamy wskazujacy element
        }
        else
        {
            data[current] = extraArray[finger2];
            finger2++; // jesli pobralismy element z drugiej podtablicy to przesuwamy wskazujacy element
        }
        current++; //przesuwamy obecny element tablicy niezaleznie z jakiej podtablicy wzielismy
    }
    /*przypadek krytyczne gdy szybciej skonczy sie pierwsza lub druga podtablica w petli powyzej */
    while (finger1 <= middleIndex)
    {
        data[current] = extraArray[finger1];
        current++;
        finger1++;
    }
}

/*implementacja algorytmu przez scalanie*/
template<typename T>
void Sort::mergeSort(T data[],T extraArray[], int leftIndex, int rightIndex)
{
    //dzielimy problem na dwa mniejsze problemy(podzial tablicy na dwa)
    int middle;
    if (leftIndex < rightIndex)
    {
        middle = (leftIndex + rightIndex) / 2;
        //dwa mniejsze problemy sortujemy - rekurencja
        mergeSort(data,extraArray, leftIndex, middle);
        mergeSort(data,extraArray, middle + 1, rightIndex);
        //metoda scalujaca dwie posortowane juz tablice
        merge(data,extraArray, leftIndex, middle, rightIndex);
    }
}

/*wyznaczanie najwiekszej wartosci na gore kopca */
template<typename T>
void Sort::validateMaxHeap(T data[],int heapSize,int parentIndex)
{
    T tmp;
    /*przypisujemy rodzicowi i dziecią kolejno odpowiednie indeksy wg wzoru */
    int maxIndex = parentIndex;
    int leftChild = parentIndex*2+1;
    int rightChild = parentIndex*2+2;

    /*jesli dziecko wieksze od rodzica to zmieniamy indeksy, najpierw sprawdz lewe potem prawe dziecko */
    if(leftChild < heapSize && data[leftChild] > data[maxIndex])
        maxIndex = leftChild;

    if(rightChild < heapSize && data[rightChild] > data[maxIndex])
        maxIndex = rightChild;

    /*jesli maxIndex zmienil indeks to zamieniami z dzieckiem warosci*/
    if( maxIndex != parentIndex)
    {
        tmp = data[maxIndex];
        data[maxIndex] = data[parentIndex];
        data[parentIndex] = tmp;
        /*sprawdzamy rekurencyjnie czy rodzic po zamianie jest w odpowiedniej pozycji */
        validateMaxHeap(data, heapSize, maxIndex);
    }      
}

/*sortowanie przez kopcowanie*/
template<typename T>
void Sort::heapSort(T data[],int length)
{
    T tmp;
    /*ustawienie najwiekszej wartosci na gorze kopca */
    for(int i = length/2-1; i >= 0; i--)
    {
        validateMaxHeap(data,length,i);
    }

    /*zamiana pierwszego elementu z ostatnim i rekurencyjnie ustawinie najwiekszego elementu na gorze kopca */
    for(int i = length-1; i > 0 ; i--)
    {
        tmp = data[i];
        data[i] = data[0];
        data[0] = tmp;
        length--;
        validateMaxHeap(data,length,0);
    }
}

/* implementacja sorotwania introspektywnego */
template<typename T>
void Sort::introSort( T data[], int firstIndex, int lastIndex, int maxDepth )
{
    if ( firstIndex < lastIndex )
    {
        if ( !maxDepth )
        {
            heapSort( data,lastIndex );
            return;
        }
        int border = partitionArray( data, firstIndex, lastIndex);
        introSort( data, firstIndex, border-1, maxDepth-1 );
        introSort( data, border+1, lastIndex, maxDepth-1 );
    }
}

/*implementacja sortowania przez wstawanie*/
template<typename T>
void Sort::insertionSort (T data[], int length)
{
    /*zmienne potrzebne do obslugi algorytmu */
    int i, j;
    T tmp;
    for (i=1; i<length; i++)
    {
        tmp=data[i];
        for (j=i; j>0 && tmp<data[j-1]; j--)
            data[j]=data[j-1];

        data[j]=tmp;
    }
}


#endif