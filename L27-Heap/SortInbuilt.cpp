#include <iostream>
#include <algorithm>
using namespace std;

bool mycompare(int a, int b) {
	return a < b;
}

int main() {

	int a[] = {5, 4, 3, 2, 1};
	int n = sizeof(a) / sizeof(int);

	sort(a, a + n, mycompare);

	for (int i = 0; i < n; ++i)
	{
		cout << a[i] << " ";
	}
	cout << endl;

	return 0;
}
















