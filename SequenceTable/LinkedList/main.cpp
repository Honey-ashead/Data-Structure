#include <iostream>
#include "List.cpp"

using namespace std;

int main() {
    List<int> list;
    for (int i = 0; i < 10; i++)
        list.Add( i+1);
    list.show();
    cout << list.Length() << endl;
    return 0;
}

