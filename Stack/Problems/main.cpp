#include "Calculator.cpp"

using namespace std;

int main() {
	Calculator cal;
	char ops[] = {'5','3','4','*','+', '#', '\0'};
	double res = cal.Run(ops);
    cout << res << endl;
	return 0;
}
