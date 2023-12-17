#include <iostream>
using namespace std;

int main() {
	char ch;
	cin >> ch;

	switch (ch) {
	case 'N':
	case 'n':
		cout << "North\n";
		break;
	case 'E':
	case 'e':
		cout << "East\n";
		break;
	case 'W':
	case 'w':
		cout << "West\n";
		break;
	case 'S':
	case 's':
		cout << "South\n";
		break;
	default:
		cout << "Invalid Input\n";
	}



	return 0;
}
















