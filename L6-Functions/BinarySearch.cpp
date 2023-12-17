#include <iostream>
using namespace std;

int binarySearch(int a[], int n, int key) {
	int s = 0;
	int e = n - 1;

	while (s <= e) {
		int m = (s + e) / 2;
		if (a[m] == key) {
			return  m;
		}
		else if (a[m] < key) {
			s = m + 1;
		}
		else {
			e = m - 1;
		}
	}

	return -1;
}

int main() {

	int a[] = {1, 2, 3, 4, 5};
	int n = sizeof(a) / sizeof(int);

	int indx = binarySearch(a, n, 11);

	cout << indx << endl;

	return 0;
}
















