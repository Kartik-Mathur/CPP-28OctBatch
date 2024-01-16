#include <iostream>
using namespace std;

int stringToInt(char*a, int n) {
	// base case
	if (n == 0) {
		return 0;
	}

	// recursive case
	int digit = a[n - 1] - '0';
	int CA = stringToInt(a, n - 1);
	return CA * 10 + digit;
}

int main() {

	char a[] = "1234";
	int n = strlen(a);
	cout << stringToInt(a, n) << endl;
	cout << stringToInt(a, n) + 20 << endl;


	return 0;
}
















