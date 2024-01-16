#include <iostream>
using namespace std;

bool isSorted(int*a, int n, int i) {
	// base case
	if (i == n - 1 || i == n) return true;

	// recursive case
	bool isChotaSorted = isSorted(a, n, i + 1);
	if (a[i] < a[i + 1] and isChotaSorted) {
		return true;
	}
	return false;
}

bool isSorted2(int *a, int n) {
	// base case
	if (n <= 1) return true;

	// recursive case
	if (a[n - 1] > a[n - 2] and isSorted2(a, n - 1)) {
		return true;
	}
	return false;
}


bool isSorted3(int *a, int n) {
	// base case
	if (n <= 1) return true;

	// recursive case
	if (a[0] < a[1] and isSorted2(a + 1, n - 1)) {
		return true;
	}
	return false;
}

int main() {

	int a[] = {1, 2, 3, -4, 5, 10};
	int n = sizeof(a) / sizeof(int);

	if (isSorted3(a, n)) {
		cout << "Array is Sorted\n";
	}
	else {
		cout << "Array is not sorted\n";
	}

	return 0;
}
















