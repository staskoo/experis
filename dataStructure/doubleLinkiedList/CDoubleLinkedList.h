#ifndef CLINKEDLIST_H
#define CLINKEDLIST_H

template<class T>
class CDoubleLinkedList
{
    class CNode
    {
        public:
            CNode(T& a_value);
            CNode();
            CNode(const T& a_value);

            CNode* m_next;
            CNode* m_prev;
            T m_value;
    };
    public:
        CDoubleLinkedList();
        ~CDoubleLinkedList();

        void PushFront(const T& a_value);
        void PushBack(const T& a_value);
        void PopFront();
        void PopBack();
        T& Front();
        T& Back();
        bool Empty() const;

        T defaultVal;
    private:
        CNode m_head;
        CNode m_tail;
};

#include "CDoubleLinkedList.cxx"

#endif //CLINKEDLIST_H