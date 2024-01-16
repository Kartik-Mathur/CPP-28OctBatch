#include <iostream>
using namespace std;

char keys[][10] = {
	"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"
};

void intToString(int n) {
	// base case
	if (n == 0) {
		return;
	}

	// recursive case
	int ld = n % 10;

	intToString(n / 10);
	cout << keys[ld] << " ";
}

int main() {

	int n = 2048;

	intToString(n);

	return 0;
}
















