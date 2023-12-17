#include <iostream>
using namespace std;

int main() {

	char ch;
	int digits = 0, characters = 0, spaces = 0, special = 0;

	ch = cin.get();
	while (ch != '$') {

		if ((ch >= 'a' and ch <= 'z') || (ch >= 'A' and ch <= 'Z')) {
			characters++;
		}
		else if (ch >= '0' and ch <= '9') {
			digits++;
		}
		else if (ch == ' ' || ch == '\n' || ch == '\t') {
			spaces++;
		}
		else {
			special++;
		}
		ch = cin.get();
	}

	cout << "Digits    : " << digits << endl;
	cout << "Characters: " << characters << endl;
	cout << "Special   : " << special << endl;
	cout << "Spaces    : " << spaces << endl;

	return 0;
}
















