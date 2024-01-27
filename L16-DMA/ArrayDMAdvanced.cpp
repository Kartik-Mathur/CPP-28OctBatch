#include <iostream>
using namespace std;

// int* createArray() {
// 	int a[] = {1, 2, 3, 4, 5};
// 	int n = sizeof(a) / sizeof(int);

// 	// Yaha yeh nahi kr skte, because a[] local array hai
// 	// createArray function khatam a[] bhi destroy ho jaega
// 	// automatically
// 	return a;
// }

int *createArray(int n, int v) {

	int *a = new int [n];
	for (int i = 0; i < 10; ++i)
	{
		a[i] = v;
	}

	return a;
}

int main() {
	int n = 10;
	int val = 1;
	int *arr = createArray(n, val);

	for (int i = 0; i < n; ++i)
	{
		cout << arr[i] << " ";
	}
	cout << endl;


	return 0;
}
















