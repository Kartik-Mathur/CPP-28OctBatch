#include <iostream>
using namespace std;

int main() {

	int n, i;
	cin >> n;

	i = 2;
	while (i < n) {
		if (n % i == 0) {
			cout << "Not Prime\n";
			return 0;
		}

		i = i + 1;
	}
	cout << "Prime\n";
	return 0;
}
















