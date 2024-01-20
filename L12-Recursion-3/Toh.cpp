#include <iostream>
using namespace std;

void toh(int n, char src, char helper, char des) {
	// base case
	if (n == 0) {
		return;
	}
	// recursive case
	// 1. n-1 discs ko src to helper lekar jaao(Recursion)
	toh(n - 1,  src  ,   des   ,   helper );
	// 2. nth disc ko manually src to des rakhdo
	cout << "Take " << n << " from " << src << " to " << des << endl;
	// 3. n-1 discs helper se des par lekar jaao(Recursion)
	toh(n - 1,  helper  ,   src      ,  des     );
}

int main() {
	int n;
	cin >> n;
	toh(n, 'A', 'B', 'C');

	return 0;
}
















