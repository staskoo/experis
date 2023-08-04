#include <cstddef>
#include <iostream>

void swapValues(int* a_first, int* b_second)
{
    int temp = *a_first;
    *a_first = *b_second;
    *b_second = temp;
}

bool insideLoop(int * a_arrayToSort, unsigned int a_size)
{
    bool isInternalLoopSwapped = false;
    for(size_t i = 0; i < a_size - 1; i++)
    {
        if(a_arrayToSort[i] > a_arrayToSort[i + 1])
        {
            isInternalLoopSwapped = true;
            swapValues(&a_arrayToSort[i],&a_arrayToSort[i+1]);
        }
    }
    return isInternalLoopSwapped;
}

void bubbleSort(int * a_arrayToSort, unsigned int a_size)
{
    if(a_arrayToSort == nullptr || a_size < 1)
    {
        return;
    }
    bool isInternalLoopSwapped = true;
    while(isInternalLoopSwapped)
    {
        isInternalLoopSwapped = insideLoop(a_arrayToSort, a_size);
        int x = 53;
    }
}

int main()
{
    int arrayToSort[] = {6, 20, 11, 8, 17, 1, 13, 50, 4};
    bubbleSort(arrayToSort, sizeof(arrayToSort)/sizeof(unsigned int));
    return 0;
}