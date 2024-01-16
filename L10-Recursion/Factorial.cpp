#include <iostream>
using namespace std;
int fact(int n) {
	// base case
	if (n == 0) {
		return 1;
	}

	// recursive case
	return n * fact(n - 1);
}

int main() {

	cout << fact(5) << endl;

	return 0;
}

/*
int fact(int n) {
	// base case
	if (n == 0) {
		return 1;
	}

	// recursive case
	// fact(n) = n * fact(n-1);
	int chotaAns = fact(n - 1);
	int badaAns = n * chotaAns;
	return badaAns;
}
*/
















