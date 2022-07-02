#include <iostream>
#include "Queue.hpp"

using namespace std;

int main()
{
	Queue<int> q;
	for (int i = 0; i < 20; ++i)
		q.Push(i);
	cout << q.Rear() << endl;
	return 0;
}