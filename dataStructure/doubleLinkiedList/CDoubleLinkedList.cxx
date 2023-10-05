#include<iostream>
#include "CDoubleLinkedList.h"

using namespace std;

template<class T>
CDoubleLinkedList<T>::CNode::CNode(T& a_value):
m_next(NULL),
m_prev(NULL),
m_value(a_value)
{
}

template<class T>
CDoubleLinkedList<T>::CNode::CNode(const T& a_value):
m_next(NULL),
m_prev(NULL),
m_value(a_value)
{
}

template<class T>
CDoubleLinkedList<T>::CNode::CNode()
{
}


template<class T>
CDoubleLinkedList<T>::CDoubleLinkedList()
{
    m_head.m_next = &m_tail;
    m_tail.m_prev = &m_head;
}


template<class T>
CDoubleLinkedList<T>::~CDoubleLinkedList()
{
}


template<class T>
void CDoubleLinkedList<T>::PushFront(const T& a_value)
{
    CNode* newNode = new CNode(a_value);
    newNode->m_next = m_head.m_next;
    m_head.m_next = newNode;

    newNode->m_prev = &m_head;
    m_head.m_next->m_next->m_prev = m_head.m_next;
}


template<class T>
void CDoubleLinkedList<T>::PushBack(const T& a_value)
{
    CNode* newNode = new CNode(a_value);

    newNode->m_next = &m_tail;
    newNode->m_prev = m_tail.m_prev;

    m_tail.m_prev = newNode;

    
    m_tail.m_prev->m_prev->m_next = m_tail.m_prev;
}


template<class T>
void CDoubleLinkedList<T>::PopFront()
{
    if(m_head.m_next != &m_tail)
    {
        CNode* holder = m_head.m_next;
        m_head.m_next = m_head.m_next->m_next;
        holder->m_next->m_prev = &m_head;
        delete holder;
    }
}


template<class T>
bool CDoubleLinkedList<T>::Empty() const
{
    return m_head.m_next == &m_tail ? true : false;
}


template<class T>
T& CDoubleLinkedList<T>::Front()
{
    return m_head.m_next != &m_tail ? m_head.m_next->m_value : defaultVal;
}

template<class T>
void CDoubleLinkedList<T>::PopBack()
{
    if(m_head.m_next != &m_tail)
    {
        CNode* holder = m_tail.m_prev;
        m_tail.m_prev = m_tail.m_prev->m_prev;
        holder->m_prev->m_next = &m_tail;
        delete holder;
    }
}

template<class T>
T& CDoubleLinkedList<T>::Back()
{
    return m_head.m_next != &m_tail ? m_tail.m_prev->m_value : defaultVal;
}