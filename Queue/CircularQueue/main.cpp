#include "circularQueue.hpp"
#include <iostream>

using namespace std;

int main()
{
	CircularQueue<int> queue(20);
	for (int i = 0; i < 20; ++i)
		queue.Push(i);
	cout << queue.Front() << endl;
	cout << queue.Rear() << endl;

	for (int i = 0; i < 10; ++i)
		queue.Pop();
	cout << queue.Front() << endl;
	cout << queue.Rear() << endl;

	return 0;
}