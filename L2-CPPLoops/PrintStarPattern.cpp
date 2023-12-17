#include <iostream>
using namespace std;

int main() {

	int n, row, i;
	cin >> n;
	int x =  1;

	row = 1;
	while (row <= n) {
		// 1. Print row times '*'
		i = 1;
		while (i <= row) {
			cout << x << ' ';
			x = x + 1;
			i = i + 1;
		}

		cout << '\n';
		row = row + 1;
	}


	return 0;
}
















