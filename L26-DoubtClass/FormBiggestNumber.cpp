#include <iostream>
#include <cmath>
using namespace std;

int findDigits(int x) {
	int cnt = 0;
	while (x > 0) {
		cnt++;
		x /= 10;
	}
	return cnt;
}

bool aPlusB_Bigger(int a, int b) {
	int digitsA = findDigits(a);
	int digitsB = findDigits(b);

	int aPlusB = a * pow(10, digitsB) + b;
	int bPlusA = b * pow(10, digitsA) + a;
	return aPlusB > bPlusA;
}

void formBiggest(int *arr, int n) {
	for (int i = 0; i < n - 1; ++i)
	{
		for (int j = 0; j < n - i - 1; ++j)
		{
			int a = arr[j];
			int b = arr[j + 1];
			if (aPlusB_Bigger(a, b)) {
				swap(arr[j], arr[j + 1]);
			}
		}
	}

	for (int i = n - 1; i >= 0; --i)
	{
		cout << arr[i];
	}
	cout << endl;
}

int32_t main() {
	int t;
	cin >> t;

	while (t--) {
		int a[100000];
		int n;

		cin >> n;

		for (int i = 0; i < n; ++i)
		{
			cin >> a[i];
		}
		formBiggest(a, n);
	}





	return 0;
}
















