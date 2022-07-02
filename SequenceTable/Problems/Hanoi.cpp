#include <iostream>

using namespace std;

void Hanoi(int n, char A, char B, char C);

int main() {
	Hanoi(3, 'A', 'B', 'C');
	return 0;
}

void Hanoi(int n, char A, char B, char C) {
	if (n == 1) {
		cout << "Move top disk from " << A << " to " << C << endl;
		return;
	} else {
		Hanoi(n-1, A, C, B);
		cout << "Move top disk from " << A << " to " << C << endl;
		Hanoi(n-1, B, A, C);
	}
}