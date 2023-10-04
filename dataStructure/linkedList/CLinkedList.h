#ifndef CLINKEDLIST_H
#define CLINKEDLIST_H


template<class T>
class CLinkedList{
    class CNode
    {
        public:
            CNode(T& m_value);
            CNode();

            CNode* m_next;
            T m_value;
    };
    public:
        CLinkedList();
        ~CLinkedList();

        void Push(T a_value);
        void Pop();
        int Front();
        bool Empty() const;
    private:
        CNode m_head;
};

#include "CLinkedList.cxx"

#endif //CLINKEDLIST_H