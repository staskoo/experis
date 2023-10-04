#include<iostream>
#include "CQueue.h"

using namespace std;


class temp
{
    public:
    temp() 
    { 
        cout << "constructor called " << endl;
    }
    ~temp() { }
    temp(const temp& t)
    {
        cout << "Copy constructor called " << endl;
    }
    temp& operator=(const temp& t)
    {
        cout << "Assignment operator called " << endl;
        return *this;
    }
};

int main()
{
    CQueue<temp> queue2(3);
    temp t;
    queue2.PushBack(t);


    CQueue<int> queue(15);
    for(int i = 0; i < 10; i++)
    {
        queue.PushBack(i);
    }
    queue.PushBack(11);
    while(queue.isEmplty() != true)
    {
        int val = queue.Front();
        cout << val << '\n';
        queue.PopFront();
    }
    int val = queue.Front();
    cout << val << '\n';
    return 0;
}