#include <iostream>

using namespace std;

template <typename T>
T sum_rec(const T list[], int len);

int factory_rec(int n);

int main()
{
    // double alst[10] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.2};
    // cout << "The sum of all elements is " << sum_rec(alst, 10) << endl;
    cout << factory_rec(5) << endl;
    return 0;
}

template <typename T>
T sum_rec(const T list[], int len)
{
    if (len <= 0)
        return 0;
    if (len == 1)
        return list[0];

    return list[len - 1] + sum_rec(list, len - 1);
}

int factory_rec(int n)
{
    if (n <= 0)
        return 0;
    if (n == 1)
        return 1;
    return n * factory_rec(n - 1);
}