#include <iostream>
using namespace std;

void updateValueBy1(int &x) {
	x = x + 1;
}

int main() {

	int a = 1;
	cout << "Before Update : " << a << endl;

	updateValueBy1(a);

	cout << "After Update  : " << a << endl;


	return 0;
}
















