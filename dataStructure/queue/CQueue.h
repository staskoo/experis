#ifndef CQUEUE_H
#define CQUEUE_H


template<class T>
class CQueue
{
    public:
        CQueue(unsigned int a_sizeOfQueue);
        ~CQueue();

        void PopFront();
        T& Front();
        void PushBack(const T& a_element);
        bool isEmplty();
        unsigned int Size();
    private:
        T** m_queue;
        unsigned int m_sizeOfQueue;
        unsigned int m_numOfElements;
        unsigned int m_beginOfQueue;
        unsigned int m_endOfQueue;

};

#include "CQueue.cxx"

#endif //CQUEUE_H