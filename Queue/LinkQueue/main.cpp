#include "LinkQueue.h"
//#include <iostream>

using namespace std;

int main() {
	LinkQueue q(90);
	q.Enqueue(10);
	q.Enqueue(20);
	q.Enqueue(30);
	q.Enqueue(40);
	q.Enqueue(50);
	q.Enqueue(60);
    q.Show();

	// cout << q.Front() << endl;

	q.Dequeue();
	q.Dequeue();
	q.Dequeue();
	q.Dequeue();
	q.Dequeue();
	q.Dequeue();
//	q.Dequeue();


	q.Dequeue();

//	q.Show();


	return 0;
}