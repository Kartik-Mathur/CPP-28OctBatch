#include <iostream>
using namespace std;

int a = -1000;

int main() {
	cout << a << endl; // -1000

	if (a > 1) {
		int a = 100;

		cout << a << endl;
		a++;
	}

	// To access Global variables we use --> ::
	// :: -> Scope resolution operator
	cout << "Global a : " << ::a << endl;
	::a = ::a + 10000;

	cout << a << endl;

	return 0;
}
















