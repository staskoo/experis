#include <stddef.h>

void swap(int* a_first, int* a_second)
{
    int temp = *a_first;
    *a_first = *a_second;
    *a_second = temp;
}

bool shakeRight(int * a_arrayToSort, size_t a_size)
{
    bool isShakeHadSwap = false;
    for(size_t i = 0; i < a_size - 1; i++)
    {
        if(a_arrayToSort[i] > a_arrayToSort[i + 1])
        {
            swap(&a_arrayToSort[i], &a_arrayToSort[i + 1]);
            isShakeHadSwap = true;
        }
    }
    return isShakeHadSwap;
}

bool shakeLeft(int * a_arrayToSort, size_t a_size)
{
    bool isShakeHadSwap = false;
    for(size_t i = a_size - 1; i > 0; i--)
    {
        if(a_arrayToSort[i] < a_arrayToSort[i - 1])
        {
            swap(&a_arrayToSort[i], &a_arrayToSort[i - 1]);
            isShakeHadSwap = true;
        }
    }
    return isShakeHadSwap;
}

void shakeSort(int * a_arrayToSort, size_t a_size)
{
    int counter = 0;
    bool isShakeHadSwap = true;
    if(a_arrayToSort == nullptr || a_size < 1)
    {
        return;
    }
    
    while(isShakeHadSwap)
    {
        if(counter % 2 == 0)
        {
            isShakeHadSwap = shakeRight(a_arrayToSort, a_size);
            a_size--;
        }
        else
        {
            isShakeHadSwap = shakeLeft(a_arrayToSort, a_size);
            a_arrayToSort = a_arrayToSort + 1;
        }
        counter++;
    }

}

int main()
{
    int arrayToSort[] = {8, 5, 11, 9 , 25, 16 , 17, 1};
    shakeSort(arrayToSort, sizeof(arrayToSort)/ sizeof(int));
    return 0;
}