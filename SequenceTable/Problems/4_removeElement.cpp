#include <iostream>
#include <vector>
using namespace std;

int removeElement(vector<int> & list, int target);
ostream & operator<<(ostream & os, const vector<int> & list);

int main() {
	vector<int> list = {1,2,3,2,2,3,6,2,7};
	int slow = removeElement(list, 2);
	for (int i = slow; i < list.size(); ++i)
		list[i] = 0;
	cout << slow << endl;
	cout << list;
	return 0;
}

int removeElement(vector<int> & list, int target) {
	int fast = 0;
	int slow = 0;

	while (fast < list.size()) {
		if (list[fast] != target) {
			list[slow] = list[fast];
			slow++;
		}
		fast++;
	}
	return slow;
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
