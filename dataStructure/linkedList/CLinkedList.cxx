#include<iostream>
#include "CLinkedList.h"

using namespace std;

template<class T>
CLinkedList<T>::CNode::CNode(T& m_value):
m_next(0),
m_value(m_value)
{
}

template<class T>
CLinkedList<T>::CNode::CNode(const T& m_value):
m_next(0),
m_value(m_value)
{
}

template<class T>
CLinkedList<T>::CNode::CNode():
m_next(0),
m_value(0)
{
}

template<class T>
CLinkedList<T>::CLinkedList()
{
}

template<class T>
CLinkedList<T>::~CLinkedList()
{
}

template<class T>
void CLinkedList<T>::Push(const T& a_value)
{
    CNode* newNode = new CNode(a_value);
    newNode->m_next = m_head.m_next;
    m_head.m_next = newNode;
}

template<class T>
void CLinkedList<T>::Pop()
{
    CNode* leavingNode = m_head.m_next;
    if(leavingNode != 0)
    {
        m_head.m_next = m_head.m_next->m_next;
        delete leavingNode;
    }
}

template<class T>
T& CLinkedList<T>::Front()
{
    static T proxy;
    return m_head.m_next != 0 ? m_head.m_next->m_value : proxy;
}

template<class T>
bool CLinkedList<T>::Empty() const
{
    return m_head.m_next == 0 ? true : false;
}
