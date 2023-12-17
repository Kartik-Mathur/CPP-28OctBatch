#include <iostream>
using namespace std;

void printTable(int start, int end, int step) {

	int f = start;
	while (f <= end) {
		// c = (5 / 9.0) * (f - 32);
		int c = (5) * (f - 32) / 9;
		cout << f << " " << c << endl;

		f = f + step;
	}
}

int main() {

	printTable(0, 300, 50);
	printTable(0, 100, 30);

	return 0;
}
















