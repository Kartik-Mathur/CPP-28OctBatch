#include <iostream>
using namespace std;

void printArray(int arr[], int n) {
	for (int i = 0; i < n; ++i)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

int sumArray() {
	int sum = 0;
	for (int i = 0; i < n; ++i)
	{
		sum += arr[i];
	}
	return sum;
}

void bubbleSort(int a[], int n) {
	for (int i = 0; i < n - 1; ++i)
	{
		for (int j = 0; j < n - 1 - i; ++j)
		{
			if (a[j] > a[j + 1]) {
				swap(a[j], a[j + 1]);
			}
		}
	}
}

int main() {

	int a[1000];
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}

	// printArray(a, n);
	bubbleSort(a, n);
	printArray(a, n);


	return 0;
}
















