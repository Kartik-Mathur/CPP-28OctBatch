#include <iostream>
using namespace std;

int main() {

	char arr[100];

	int n;
	cin >> n;

	cin.get();

	for (int i = 0; i < n; ++i)
	{
		cin.getline(arr, 100);
		cout << arr << endl;
	}

	return 0;
}
















