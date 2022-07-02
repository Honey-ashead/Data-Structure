#include "LinearList.h"
#include <iostream>
using namespace std;

template <class T>
LinearList<T>::LinearList(int sz)
{
    if (sz > 0)
    {
        maxSize = sz;
        last = 0;
        data = new T [maxSize];
        if (data == nullptr)
        {
            cerr << "Fail to allocate space!" << endl;
            exit(1);
        }

    }
}

template <class T>
int LinearList<T>::Length() {
    return this -> length;
}

template <class T>
int LinearList<T>::Size(){
    return this -> maxSize;
}

template <class T>
bool LinearList<T>::getData(int i, T &x) {
    if (i <= last && i >= 0)
    {
        x = data[i];
        return true;
    }
    return false;
}

template <class T>
bool LinearList<T>::setData(int i, T &x) {
    if (i <= last && i >= 0)
    {
        x = data[i];
        return true;
    }
    return false;
}

template <class T>
bool LinearList<T>::isEmpty() const {
    return last == -1;
}

template <class T>
bool LinearList<T>::isFull() const {
    return last == maxSize - 1;
}

template <class T>
LinearList<T>::LinearList(const LinearList<T> &L){
    maxSize = L.maxSize;
    last = L.Length();
    data = new T [maxSize];
    if (data == nullptr)
    {
        cerr << "Fail to allocate space!" << endl;
        exit(1);
    }
    T &value = 0;
    for (int i = 0; i < last; i++)
    {
        L.getData(i, value);
        data[i] = value;
    }
}

template <class T>
int LinearList<T>::Search(const T &x) const {
    for (int i = 0; i < last; i++)
    {
        if (data[i] == x)
            return i;
    }
    return -1;
}

template <class T>
int LinearList<T>::Locate(int i) const {
    if ( i >= 0 && i < last)
    {
        return i;
    }
    return -1;
}

template <class T>
void LinearList<T>::Resize(int newSize){
    if (newSize < 0)
    {
        cerr << "Invalid size!" << endl;
        exit(1);
    }
    if (newSize != maxSize)
    {
        T * newArray = new T [newSize];
        if (newArray == nullptr)
        {
            cerr << "Fail to allocate memory!" << endl;
            exit(1);
        }
        int n = last;
        T * srcptr = data;
        T * destptr = newArray;

        while (n-- >= 0)
            *destptr = *srcptr;
        delete data;
        data = newArray;
        maxSize = newSize;
    }
    else
        cout << "Space is the same!" << endl;
}

template <class T>
bool LinearList<T>::Insert(int i, T x) {
    if (last == maxSize - 1)
        return false;
    if (i < 0 || i > last + 1)
        return false;
    for (int j = last; j >= i; j--)
        data[j+1] = data[j];
    last++;
    data[i] = x;
    return true;
}

template <class T>
bool LinearList<T>::Remove(int i, T &x) {
    if (last == -1)
        return false;
    if (i < 0 || i > last + 1)
        return false;
    x = data[i];
    for (int j = i; j < last + 1; j++)
        data[j-1] = data[j];
    last--;
    return true;
}

template<typename T>
LinearList<T>::~LinearList() {
    delete [] data;
}
