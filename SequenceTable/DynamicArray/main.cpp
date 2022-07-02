#include <iostream>
#include "LinearList.cpp"
using namespace std;

int main()
{
    LinearList<int> list;
    int a = 10;

    list.Insert(0, 10);
    list.getData(0, a);
    cout << "A = " << a << endl;
}