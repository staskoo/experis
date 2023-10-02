#ifndef CLINKEDLIST_H
#define CLINKEDLIST_H


class CDoubleLinkedList
{
    class CNode
    {
        public:
            CNode(int a_value);
            CNode();

            CNode* m_next;
            CNode* m_prev;
            int m_value;
    };
    public:
        CDoubleLinkedList();
        ~CDoubleLinkedList();

        void PushFront(int a_value);
        void PopFront();
        void PopBack();
        int Front();
        int Back();
        bool Empty() const;
    private:
        CNode m_head;
        CNode m_tail;
};

#include "CDoubleLinkedList.cxx"

#endif //CLINKEDLIST_H