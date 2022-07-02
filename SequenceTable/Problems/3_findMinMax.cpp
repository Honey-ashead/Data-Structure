#include <iostream>
#include <vector>

using namespace std;

void findMinMax(vector<int> list, int& min, int& max);

int main() {
	vector<int> list = {132,43,65,12,98,56,42,534};
	int min;
	int max;
	findMinMax(list, min, max);
	cout << "min = " << min << ", max = " << max << endl;
}

void findMinMax(vector<int> list, int& min, int& max) {
	min = list[0];
	max = list[0];
	for (int i = 1; i < list.size(); ++i) {
		if (list[i] > max)
			max = list[i];
		else if (list[i] < min)
			min = list[i];
	}
}
