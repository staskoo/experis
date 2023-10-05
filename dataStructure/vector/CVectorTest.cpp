#include<iostream>
#include "CVector.h"

using namespace std;


template <typename Object>
class Vector
{
    public:
    Vector()
    {
         objects = new Object[ 10 ];
    }
    Object & at( int index )
    {

        return objects[ index ];
    }

    const Object & at( int index ) const
    {
        return objects[ index ];
    }

    void push_back( const Object & x )
    {
        objects[ theSize++ ] = x;
    }

    Object & operator[]( int index )
    {
        return objects[ index ];
    }

    const Object & operator[]( int index ) const
    {
        return objects[ index ];
    }

  private:
    int theSize;
    int theCapacity;
    Object* objects;
};

class temp
{
    public:
    temp() 
    { 
        cout << "constructor called " << endl;
    }
    ~temp() { }
    temp(const temp& t)
    {
        cout << "Copy constructor called " << endl;
    }
    temp& operator=(const temp& t)
    {
        cout << "Assignment operator called " << endl;
        return *this;
    }
};

int main()
{
    Vector<int> testVec;
    testVec[0] = 1;
    cout << testVec[0] << "\n";

    CVector<temp> vector(3);
    // temp t;
    // vector.PushBack(t);

    CVector<int> vector2(5);
    vector2.PushBack(1);
    vector2.PushBack(2);
    vector2.PushBack(3);
    cout << vector2.Front() << "\n";
    while(vector2.isEmplty() != true)
    {
        cout << vector2.Back() << "\n";
        vector2.PopBack();
    }

    cout << vector2.Front() << "\n";
    cout << vector2.Back() << "\n";

    CVector<char> vector3(5);
    vector3.PushBack('1');
    while(vector3.isEmplty() != true)
    {
        cout << vector3.Back() << "\n";
        vector3.PopBack();
    }

    CVector<int> vector4(10);
    for(int i = 0; i < 15; i++)
    {
       vector4.Set(i, i);
    }
    for(unsigned int i = 0; i < 15; i++)
    {
        cout << vector4.Get(i) << "\n";
    }

    return 0;
}