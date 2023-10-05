#include<iostream>
#include "CVector.h"

using namespace std;

template<class T>
CVector<T>::CVector(unsigned int a_sizeOfVector):
m_noElemetsInVctor(new T()),
m_sizeOfVector(a_sizeOfVector),
m_numOfElements(0),
m_vector(new T*[a_sizeOfVector])
{
}


template<class T>
CVector<T>::~CVector()
{
    delete m_noElemetsInVctor;
    for(unsigned int element = 0; element < m_numOfElements; element++)
    {
        delete m_vector[element];
    }
    delete[] m_vector;
}


template<class T>
void CVector<T>::PopBack()
{
    if(m_numOfElements > 0)
    {
        delete m_vector[--m_numOfElements];     
    } 
}


template<class T>
void CVector<T>::PushBack(const T& a_value)
{
    m_vector[m_numOfElements++] = new T(a_value);
}

template<class T>
void CVector<T>::Set(unsigned int a_location, T& a_value)
{
    if(m_sizeOfVector > a_location)
    {
        m_vector[m_numOfElements++] = new T(a_value);
    }
}


template<class T>
T& CVector<T>::Get(unsigned int a_location)
{
    return m_numOfElements > a_location ? *m_vector[a_location] : *m_noElemetsInVctor;
}


template<class T>
bool CVector<T>::isEmplty()
{
    return m_numOfElements == 0 ? true : false;
}


template<class T>
unsigned int CVector<T>::Size()
{
    return m_numOfElements;
}


template<class T>
T& CVector<T>::Front()
{
    return m_numOfElements > 0 ? *m_vector[0] : *m_noElemetsInVctor;
}


template<class T>
T& CVector<T>::Back()
{
    return m_numOfElements > 0 ? *m_vector[m_numOfElements - 1] : *m_noElemetsInVctor;
}
