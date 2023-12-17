#include <iostream>
using namespace std;

int main() {

	int b[50] = {1};
	// b[]: [1,0,0,0,0,0,0,........0]
	int a[] = {5, 3, 2, 6, 7, 8};
	int n = sizeof(a) / sizeof(int);
	int key, i;

	cout << "Enter key to search: ";
	cin >> key;

	for (i = 0; i < n; ++i)
	{
		if (a[i] == key) {
			cout << key << " Found at index: " << i << endl;
			break;
		}
	}

	if (i == n) {
		cout << "Key not found\n";
	}

	return 0;
}
















