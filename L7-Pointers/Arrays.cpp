#include <iostream>
using namespace std;

int main() {

	int a[] = {1, 2, 3, 4, 5};
	int n = sizeof(a) / sizeof(int);
	int *p = a;
	for (int i = 0; i < n; ++i)
	{
		// cout << *(p + i) << " ";
		cout << p[i] << " "; // a[i] == *(a+i)
	}
	cout << endl;

	return 0;
}
















