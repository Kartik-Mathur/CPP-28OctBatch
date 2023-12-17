#include <iostream>
using namespace std;

int factorial(int number) {
	for (int i = number - 1; i > 0; --i)
	{
		number = number * i;
	}
	return number;
}

int fact(int n) {
	int ans = 1;

	for (int i = 1; i <= n; ++i)
	{
		ans = ans * i;
	}

	return ans;
}

int ncr(int n, int r) {
	int fn = fact(n);
	int fr = fact(r);
	int fnr = fact(n - r);

	int ans = fn / (fr * fnr);
	return ans;
}

int main() {

	int n = 5;
	cout << ncr(5, 2) << endl;


	return 0;
}
















