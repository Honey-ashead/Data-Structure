#include <iostream>

using namespace std;
int rFib(int n);
int iFib(int n);

int main() {
	int n = 30;
	// cout << rFib(n) << endl;
	cout << iFib(n) << endl;
	return 0;
}

// 递归实现斐波那契数列
int rFib(int n) {
	if (n == 0 || n == 1)
		return n;
	return iFib(n-1) + iFib(n-2);
}

// 迭代实现斐波那契数列
int iFib(int n) {
	if (n == 0 || n == 1)
		return n;
	int sum;
	int prev = 0;
	int curr = 1;
	for (int i = 1; i < n; i++) {
		sum = prev + curr;
		prev = curr;
		curr = sum;
	}
	return curr;
}