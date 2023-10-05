#include<iostream>
#include "CDoubleLinkedList.h"

using namespace std;

int main()
{
    CDoubleLinkedList<int> doubleList1;
    doubleList1.PushFront(3);
    doubleList1.PushFront(4);
    doubleList1.PushFront(5);
    while(doubleList1.Empty() == false)
    {
        cout << doubleList1.Front() << "\n";
        doubleList1.PopFront();
    }
    

    CDoubleLinkedList<int> doubleList2;
    doubleList2.PushFront(3);
    doubleList2.PushFront(4);
    doubleList2.PushFront(5);
    while(doubleList2.Empty() == false)
    {
        cout << doubleList2.Back() << "\n";
        doubleList2.PopBack();
    }

    CDoubleLinkedList<char> doubleList3;
    doubleList3.PushBack('3');
    doubleList3.PushBack('4');
    doubleList3.PushBack('5');
    while(doubleList3.Empty() == false)
    {
        cout << doubleList3.Back() << "\n";
        doubleList3.PopBack();
    }

    return 0;
}