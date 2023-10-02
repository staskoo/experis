#include<iostream>
#include "CLinkedList.h"

using namespace std;

int main()
{
    CLinkedList<int> list1;
    list1.Push(3);
    list1.Push(4);
    list1.Push(5);
    while(list1.Empty() == false)
    {
        cout << list1.Front() << "\n";
        list1.Pop();
    }
    
    return 0;
}