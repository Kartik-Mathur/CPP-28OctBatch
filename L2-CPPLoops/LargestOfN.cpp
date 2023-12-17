#include <iostream>
#include <climits> // INT_MAX: 2^31 - 1, INT_MIN: -2^31
using namespace std;

int main() {
	int n, i, number;
	int largest;
	cin >> n;

	largest = INT_MIN;

	i = 1;
	while (i <= n) {
		cin >> number;

		if (number > largest) {
			largest = number;
		}

		i = i + 1;
	}

	cout << "Largest Number is : " << largest << endl;

	return 0;
}
















