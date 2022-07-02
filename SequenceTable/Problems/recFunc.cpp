// 逆序打印数组中数组的递归解法
#include <iostream>

using namespace std;

void reversePrint(int * list, int n);

int main() {
	int a[10] = {1,2,3,4,5,6,7,8,9,10};
	reversePrint(a, 10);
	cout << endl;
	return 0;
}

void reversePrint(int * list, int n) {
	if (n == 1) {
		cout << list[0] << " ";
		return;
	}
	cout << list[n-1] << " ";
	reversePrint(list, n-1);
}