#include<iostream>
#include "CDoubleLinkedList.h"

using namespace std;

int main()
{
    CDoubleLinkedList doubleList1;
    doubleList1.PushFront(3);
    doubleList1.PushFront(4);
    doubleList1.PushFront(5);
    while(doubleList1.Empty() == false)
    {
        cout << doubleList1.Front() << "\n";
        doubleList1.PopFront();
    }
    

    CDoubleLinkedList doubleList2;
    doubleList2.PushFront(3);
    doubleList2.PushFront(4);
    doubleList2.PushFront(5);
    while(doubleList2.Empty() == false)
    {
        cout << doubleList2.Back() << "\n";
        doubleList2.PopBack();
    }

    return 0;
}