#include <iostream>
using namespace std;

int main() {

	int a[100][100];

	int n = 5, m = 5;
	// cin >> n >> m;

	int number = 1;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			a[i][j] = number++;
		}
	}

	for (int rows = 0; rows < n; ++rows)
	{
		for (int cols = 0; cols < m; ++cols)
		{
			cout << a[rows][cols] << " ";
		}
		cout << endl;
	}

	int key, j, i;
	cin >> key;

	for (i = 0; i < n; ++i)
	{
		for (j = 0; j < m; ++j)
		{
			if (a[i][j] == key) {
				cout << key << " found at index: " << i << ", " << j << endl;
				break;
			}
		}

		// break execute hua, ya j == m ho gaya hoga
		if (j < m) {
			break;
		}
	}

	if (i == n) {
		cout << "Key not found\n";
	}
	return 0;
}
















