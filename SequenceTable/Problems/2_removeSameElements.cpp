#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

void removeSameElements(vector<int> & list);
void removeOrderedSameElements(vector<int> & list);
ostream & operator<<(ostream & os, const vector<int> & list);

int main() {
	vector<int> list = {3,9,1,6,3,6,9,1,2,7};
	removeSameElements(list);
	cout << list;
	return 0;
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

void removeOrderedSameElements(vector<int> & list) {
	if (list.size() < 2)
		return;
	// sort(list.begin(), list.end());
	int slow = 0;
	int fast = 1;
	vector<int> ans;
	ans.push_back(list[slow]);
	while (fast < list.size() - 1) {
		if (list[fast] != list[slow]) {
			ans.push_back(list[fast]);
			slow = fast;
			// fast++;
		}
		fast++;
	}
	list = ans;
}

void removeSameElements(vector<int> & list) {
	map<int,int> dict;
	vector<int> ans;
	for (int num: list) {
		if (dict.count(num) == 0) {
			dict[num] = 1;
			ans.push_back(num);
		}
	}
	list = ans;
}