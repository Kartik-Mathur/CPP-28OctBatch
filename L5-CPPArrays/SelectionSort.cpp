#include <iostream>
using namespace std;

int main() {

	int a[] = {5, 4, 3, 2, 1};
	int n = sizeof(a) / sizeof(int);

	for (int i = 0; i < n - 1; ++i)
	{
		int m = i;

		for (int j = i + 1; j < n; ++j)
		{
			if (a[j] < a[m]) {
				m = j;
			}
		}
		swap(a[m], a[i]);
	}

	for (int i = 0; i < n; ++i)
	{
		cout << a[i] << " ";
	}
	cout << endl;

	return 0;
}
















