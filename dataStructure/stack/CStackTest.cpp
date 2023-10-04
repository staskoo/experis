#include<iostream>
#include "CStack.h"

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
    CStack<temp> stack2(3);
    temp t;
    stack2.Push(t);


    CStack<int> stack(15);
    for(int i = 0; i < 10; i++)
    {
        stack.Push(i);
    }
    stack.Push(11);
    while(stack.isEmplty() != true)
    {
        int val = stack.Top();
        cout << val << '\n';
        stack.Pop();
    }
    int val = stack.Top();
    cout << val << '\n';
    return 0;
}