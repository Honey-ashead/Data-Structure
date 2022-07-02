#include <iostream>
#include <cmath>

using namespace std;

void Hanoi(int n, char A, char B, char C);

int main()
{
    // Hanoi(3, 'A', 'B', 'C');
    cout << pow(2, 20);
    return 0;
}

void Hanoi(int n, char A, char B, char C)
{
    // base case
    if (n == 1)
    {
        cout << "Move top disk from " << A << " to " << C << endl;
        return;
    }
    Hanoi(n - 1, A, C, B);
    cout << "Move top disk from " << A << " to " << C << endl;
    Hanoi(n - 1, B, A, C);
}