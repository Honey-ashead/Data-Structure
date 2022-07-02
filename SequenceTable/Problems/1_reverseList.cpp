#include <iostream>
#include <vector>

using namespace std;

void reverseList(vector<int> & list);
ostream & operator<<(ostream & os, const vector<int> & list);

int main() {
	vector<int> v = {1,2,3,6,5,4};
	reverseList(v);
	cout << v;
	return 0;
}

void reverseList(vector<int> & list) {
	if (list.size() == 1)
		return;
	int first = 0;
	int last = list.size() - 1;
	while (first < last) {
		int temp = list[first];
		list[first] = list[last];
		list[last] = temp;

		last--;
		first++;
	}
}

ostream & operator<<(ostream & os ,const vector<int> & list) {
	int i = 0;
	cout << "{";
	for (i = 0; i < list.size() - 1; ++i) {
		cout << list[i] << ", ";
	}
	cout << list[i];
	cout << "}" << endl;
	return os;
}