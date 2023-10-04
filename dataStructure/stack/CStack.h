#ifndef CSTACK_H
#define CSTACK_H


template<class T>
class CStack
{
    public:
        CStack(unsigned int a_sizeOfStack);
        ~CStack();

        void Pop();
        T& Top();
        void Push(const T& a_element);
        bool isEmplty();
        unsigned int Size();
    private:
        unsigned int m_sizeOftack;
        unsigned int m_numOfElements;
        T** m_stack;
};

#include "CStack.cxx"

#endif //CSTACK_H