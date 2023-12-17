#include <iostream>
using namespace std;

int main() {

	char ch;
	cin >> ch;

	// store the character into integer
	int a = ch;
	if (ch >= 'A' and ch <= 'Z') {
		cout << "Uppercase\n";
	}
	else if (ch >= 'a' and ch <= 'z') {
		cout << "Lowercase\n";
	}

	// if (a >= 65 and a <= 90) {
	// 	cout << "Uppercase\n";
	// }
	// else if (a >= 97 and a <= 122) {
	// 	cout << "Lowercase\n";
	// }


	return 0;
}
















