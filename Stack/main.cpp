#include <iostream>
#include "Stack.hpp"
using namespace std;


void myCopy(int * start, const int * end, int * target);

int main()
{
    Stack<double> s(10);
    for (int i = 0; i < 6; i++)
    {
        s.Push(i);
        cout << s.Top() << endl;
    }
//    int * q = new int[5] {1,2,3,4,5};
//    int * p = new int[10] {6,7,8,9,10,11,12,13,14,15};
//    myCopy(q, q+5, p);
//    for (int i = 0; i < 5; i++)
//        cout << p[i] << " ";
//    cout << endl;
    return 0;
}

void myCopy(int * start, const int * end, int * target) {
    while (start < end) {
        *target++ = *start++;
    }
    start = target;
}