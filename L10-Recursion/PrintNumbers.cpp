#include <iostream>
using namespace std;

void printNumberDec(int n) {
	// base case
	if (n == 0) return;

	// recursive case
	// recursion ki call se pehle ka kaam
	cout << n << " ";
	printNumberDec(n - 1); // recursion ki call

	// recursion ki call ke baad ka kaam
}

int main() {

	printNumberDec(4);

	return 0;
}
















