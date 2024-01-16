#include <iostream>
using namespace std;

void copy(char *l, char *a) {
	int lena = strlen(a);
	for (int i = 0; i <= lena; ++i)
	{
		l[i] = a[i];
	}
}

int main() {
	char arr[100];
	int maxLen = 0;
	char largest[1000];

	int n;
	cin >> n;

	cin.get();

	for (int i = 0; i < n; ++i)
	{
		cin.getline(arr, 100);
		int lenArr = strlen(arr);

		if (lenArr > maxLen) {
			maxLen = lenArr;
			copy(largest, arr);
		}
	}

	cout << "Largest: " << largest << endl;

	return 0;
}
















