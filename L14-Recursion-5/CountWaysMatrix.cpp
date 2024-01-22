#include <iostream>
using namespace std;

int ways(int n, int m) {
	// base case
	if (n == 0 and m == 0) {
		return 1;
	}
	if (n < 0 || m < 0) return 0;

	// recursive case
	return ways(n - 1, m) + ways(n, m - 1);
}

int main() {

	int n, m;
	cin >> n >> m;
	cout << ways(n, m) << endl;

	return 0;
}
















