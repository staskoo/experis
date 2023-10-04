#include<iostream>
#include "CStack.h"

using namespace std;

template<class T>
CStack<T>::CStack(unsigned int a_sizeOfStack):
m_sizeOftack(a_sizeOfStack),
m_numOfElements(0),
m_stack(new T*[a_sizeOfStack])
{
}


template<class T>
CStack<T>::~CStack()
{
    for(unsigned int element = 0; element < m_numOfElements; element++)
    {
        delete m_stack[element];
    }
    delete[] m_stack;
}


template<class T>
void CStack<T>::Pop()
{
    if(m_numOfElements > 0)
    {
        --m_numOfElements;
        T* tempObject = m_stack[m_numOfElements];
        delete tempObject;
        
    }
    
}


template<class T>
T& CStack<T>::Top()
{
    static T safeValue;
    return m_numOfElements == 0 ? safeValue : *m_stack[m_numOfElements - 1];
}


template<class T>
void CStack<T>::Push(const T& a_element)
{
    T* tempObject = new T(a_element);
    m_stack[m_numOfElements] = tempObject;
    ++m_numOfElements;
}


template<class T>
bool CStack<T>::isEmplty()
{
    return m_numOfElements == 0 ? true : false;
}


template<class T>
unsigned int CStack<T>::Size()
{
    return m_numOfElements;
}
