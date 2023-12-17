#include <iostream>
using namespace std;

int main() {

	int a[] = {5, 4, 3, 2, 1};
	int n = sizeof(a) / sizeof(int);
	int i, j;

	for (i = 1; i < n; ++i)
	{
		int hand = a[i];

		for (j = i - 1; j >= 0; --j)
		{
			if (a[j] > hand) a[j + 1] = a[j];
			else break;
		}å

		a[j + 1] = hand;
	}

	for (int i = 0; i < n; ++i)
	{
		cout << a[i] << " ";
	}
	cout << endl;


	return 0;
}
















