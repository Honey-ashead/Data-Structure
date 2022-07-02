#include <iostream>

using namespace std;

long long rfact(int n);
long long ifact(int n);

int main() {
	int n = 20;
	cout << rfact(n) << endl;
	cout << ifact(n) << endl;
	return 0;
}

long long rfact(int n) {
	if (n == 0)
		return 1;
	return n * rfact(n-1);
}

long long ifact(int n) {
	long long result = 1;
	for (int i = 2; i <= n; ++i)
		result *= i;
	return result;
}