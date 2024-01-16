#include <iostream>
using namespace std;

int main() {

	int a[][3] = {
		{1, 2, 3},
		{4, 5, 6},
		{7, 8, 9}
	};

	for (int rows = 0; rows < 3; ++rows)
	{
		for (int cols = 0; cols < 3; ++cols)
		{
			cout << a[rows][cols] << " ";
		}
		cout << endl;
	}






	return 0;
}
















