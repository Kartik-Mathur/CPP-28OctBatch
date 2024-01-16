#include <iostream>
using namespace std;

int main() {

	int a[100][100];

	int n = 3, m = 4;
	// cin >> n >> m;

	int number = 1;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			a[i][j] = number++;
		}
	}


	for (int col = 0; col < m; ++col)
	{
		if (col % 2 == 0) {
			// row ko lekar jaao 0->n-1
			for (int row = 0; row < n; ++row)
			{
				cout << a[row][col] << " ";
			}
		} else {
			// row ko lekar jaao n-1 -> 0
			for (int row = n - 1; row >= 0; --row)
			{
				cout << a[row][col] << " ";
			}
		}
	}

	cout << endl;
	return 0;
}
















