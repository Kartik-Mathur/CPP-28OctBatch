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

	int key = 300;

	int i = 0, j = m - 1;

	while (i<n and j >= 0) {
		if (a[i][j] == key) {
			cout << key << " found at index: " << i << "," << j << endl;
			break;
		}
		else if (a[i][j] < key) i++;
		else j--;
	}

	if (i == n) {
		cout << "Key not found\n";
	}

	return 0;
}
















