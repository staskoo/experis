#include "CQueue.h"

using namespace std;

template<class T>
CQueue<T>::CQueue(unsigned int a_sizeOfQueue):
m_queue(new T*[a_sizeOfQueue]),
m_sizeOfQueue(a_sizeOfQueue),
m_numOfElements(0),
m_beginOfQueue(0),
m_endOfQueue(0)
{
}


template<class T>
CQueue<T>::~CQueue()
{
    for(unsigned int element = 0; element < m_numOfElements; element++)
    {
        delete m_queue[(m_beginOfQueue + element) % m_sizeOfQueue];
    }
    delete[] m_queue;
}


template<class T>
void CQueue<T>::PopFront()
{
    if(m_numOfElements > 0)
    {
        --m_numOfElements;
        delete m_queue[m_beginOfQueue];
        m_beginOfQueue =  (m_beginOfQueue + 1 ) % m_sizeOfQueue;
    }
}


template<class T>
T& CQueue<T>::Front()
{
    static T defaultVariable;
    return m_numOfElements == 0 ? defaultVariable : *m_queue[m_beginOfQueue];
}


template<class T>
void CQueue<T>::PushBack(const T& a_element)
{
    if(m_numOfElements < m_sizeOfQueue)
    {
        m_queue[m_endOfQueue] = new T(a_element);
        ++m_numOfElements;
        m_endOfQueue =  (m_endOfQueue + 1 ) % m_sizeOfQueue;
    }
}


template<class T>
bool CQueue<T>::isEmplty()
{
    return m_numOfElements == 0 ? true : false;
}


template<class T>
unsigned int CQueue<T>::Size()
{
    return m_numOfElements;
}
