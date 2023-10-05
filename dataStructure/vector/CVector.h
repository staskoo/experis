#ifndef CVECTOR_H
#define CVECTOR_H


template<class T>
class CVector
{
    public:
        CVector(unsigned int a_sizeOfVector);
        ~CVector();

        void PopBack();
        void PushBack(const T& a_value);
        T& Front();
        T& Back();
        bool isEmplty();
        unsigned int Size();
        void Set(unsigned int a_location, T& a_value);
        T& Get(unsigned int a_location);
        T* m_noElemetsInVctor;
    private:
        unsigned int m_sizeOfVector;
        unsigned int m_numOfElements;
        T** m_vector;
};

#include "CVector.cxx"

#endif //CVECTOR_H