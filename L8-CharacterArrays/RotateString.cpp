#include <iostream>
using namespace std;

void rotateString(char* a, int n) {
	int lena = strlen(a);
	n %= lena;
	// cout << "Initially: " << a << endl;
	// 1. Shift all the characters n position ahead
	int i = lena - 1;
	while (i >= 0) {
		a[i + n] = a[i];
		i--;
	}
	// cout << "After shifting: " << a << endl;
	// 2. bring last n characters to front
	i = 0;
	int j = lena;
	while (i < n) {
		a[i] = a[j];
		i++;
		j++;
	}

	// cout << a << endl;
	a[lena] = '\0';
	// cout << a << endl;
}

int main() {

	char a[100] = "Coding";
	int n = 40;

	rotateString(a, 50000);
	cout << a << endl;

	// cout << a << endl;

	return 0;
}
















