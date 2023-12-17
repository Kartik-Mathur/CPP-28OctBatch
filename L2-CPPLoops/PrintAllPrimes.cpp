#include <iostream>
using namespace std;

int main() {

	int n, i, number;


	cin >> number;
	n = 2;
	while (n <= number) {

		i = 2;
		while (i < n) {
			if (n % i == 0) {
				break; // Yeh jab execute hoga, loop se bahar kr dega
				// and i<n hoga humesha,  tabhi yeh chl skta h
			}

			i = i + 1;
		}

		if (i == n) {
			cout << n << " ";
		}

		n = n + 1;
	}









	return 0;
}
















