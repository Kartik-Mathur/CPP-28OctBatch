#include <iostream>
using namespace std;

void printArray(int arr[], int n) {
	for (int i = 0; i < n; ++i)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

void mergeArrays(int a[], int n, int b[], int m) {
	int i = n - 1;
	int j = m - 1;
	int k = m + n - 1;
	while (i >= 0 and j >= 0) {
		if (a[i] > b[j]) {
			a[k] = a[i];
			k--;
			i--;
		}
		else {
			a[k] = b[j];
			k--;
			j--;
		}
	}

	// Agar j ke elements bach gaye toh unhe a[] mei insert krdo
	while (j >= 0) {
		a[k] = b[j];
		k--;
		j--;
	}
}

int main() {


	int a[7] = {3, 5, 7};
	int n = 3;

	int b[] = {1, 2, 4, 6};
	int m = 4;

	mergeArrays(a, n, b, m);
	printArray(a, n + m);



	return 0;
}
















