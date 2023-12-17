#include <iostream>
using namespace std;

int main() {

	int n, i, no;
	cin >> n;

	int row = 1;
	while (row <= n) {
		// 1. Print n-row times spaces
		i = 1;
		while (i <= n - row) {
			cout << " ";
			i = i + 1;
		}

		// 2. Print row times increasing numbers, starting from: row
		i = 1;
		no = row;
		while (i <= row) {
			cout << no;
			no = no + 1;
			i = i + 1;
		}
		// 3. Print row-1 times decreasing numbers, starting from: 2*row-2
		i = 1;
		no = row * 2 - 2;
		while (i <= row - 1) {
			cout << no;
			no = no - 1;
			i = i + 1;
		}

		cout << '\n';
		row = row + 1;
	}

	return 0;
}
















