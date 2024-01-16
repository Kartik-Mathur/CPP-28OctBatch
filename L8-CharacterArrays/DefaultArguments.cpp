#include <iostream>
using namespace std;
int add(int a = 0, int b = 0, int c = 0) {
	return a + b + c;
}

int main() {

	int a = 10, b = 20, c = 30;

	cout << add(a, b, c) << endl;
	cout << add(a, b) << endl;
	cout << add(a) << endl;
	cout << add() << endl;

	return 0;
}
















