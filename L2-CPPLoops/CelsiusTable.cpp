#include <iostream>
using namespace std;

int main() {
	int f, c;
	int start = 0;
	int end = 300;
	int step = 20;

	f = start;
	while (f <= end) {
		// c = (5 / 9.0) * (f - 32);
		c = (5) * (f - 32) / 9;
		cout << f << " " << c << endl;

		f = f + step;
	}

	return 0;
}
















