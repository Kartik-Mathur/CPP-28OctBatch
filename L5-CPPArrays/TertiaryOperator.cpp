#include <iostream>
using namespace std;

int main() {

	int a = 2;

	a % 2 == 0 ? cout << "Even\n" : cout << "Odd\n";

	// We can also assign values using this
	bool x = ( a % 2 == 0 ? true : false );

	if (x == true) {
		cout << "Even hai\n";
	}
	else {
		cout << "Odd hai\n";
	}


	return 0;
}
















