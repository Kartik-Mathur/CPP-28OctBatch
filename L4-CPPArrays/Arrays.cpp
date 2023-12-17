#include <iostream>
using namespace std;

int main() {

	int a[500]; // max size: 10^6
	int n;

	// a[0] = 5;
	// a[1] = 10;
	// a[2] = 15;
	// a[3] = 20;
	// a[4] = 25;
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		// a[i] = (i + 1) * 5;
		cin >> a[i];
	}
	for (int i = 0; i < n; ++i)
	{
		cout << a[i] << " ";
	}
	cout << endl;

	return 0;
}
















