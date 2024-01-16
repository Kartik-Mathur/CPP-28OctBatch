#include <iostream>
using namespace std;

int main() {

	int a[100][100];

	int n, m;
	cin >> n >> m;

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

	return 0;
}
















