#include<iostream>
#include "CDoubleLinkedList.h"

using namespace std;

CDoubleLinkedList::CNode::CNode(int a_value):
m_next(NULL),
m_prev(NULL),
m_value(a_value)
{

}


CDoubleLinkedList::CNode::CNode()
{

}

CDoubleLinkedList::CDoubleLinkedList()
{
    m_head.m_next = &m_tail;
    m_tail.m_prev = &m_head;
}

CDoubleLinkedList::~CDoubleLinkedList()
{
}

void CDoubleLinkedList::PushFront(int a_val)
{
    CNode* newNode = new CNode(a_val);
    newNode->m_next = m_head.m_next;
    m_head.m_next = newNode;

    newNode->m_prev = &m_head;
    m_head.m_next->m_next->m_prev = m_head.m_next;
}


void CDoubleLinkedList::PopFront()
{
    if(m_head.m_next != &m_tail)
    {
        CNode* holder = m_head.m_next;
        m_head.m_next = m_head.m_next->m_next;
        holder->m_next->m_prev = &m_head;
    }
}


bool CDoubleLinkedList::Empty() const
{
    return m_head.m_next == &m_tail ? true : false;
}


int CDoubleLinkedList::Front()
{
    int val = 0;
    if(m_head.m_next != &m_tail)
    {
        val = m_head.m_next->m_value;
    }
    return val;
}

void CDoubleLinkedList::PopBack()
{
    if(m_head.m_next != &m_tail)
    {
        CNode* holder = m_tail.m_prev;
        m_tail.m_prev = m_tail.m_prev->m_prev;
        holder->m_prev->m_next = &m_tail;
    }
}

int CDoubleLinkedList::Back()
{
    int val = 0;
    if(m_head.m_next != &m_tail)
    {
        val = m_tail.m_prev->m_value;
    }
    return val;
}