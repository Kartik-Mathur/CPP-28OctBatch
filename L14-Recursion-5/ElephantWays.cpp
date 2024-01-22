#include <iostream>
using namespace std;

int elephantWays(int n, int m) {
	// base case
	if (n == 0 and m == 0) return 1;
	if (n < 0 || m < 0) return 0;

	// recursive case
	int ans = 0;
	for (int k = 0; k < n; ++k)
	{
		ans += elephantWays(k, m);
	}
	for (int k = 0; k < m; ++k)
	{
		ans += elephantWays(n, k);
	}
	return ans;
}

int main() {

	int n, m;
	cin >> n >> m;

	cout << elephantWays(n, m) << endl;

	return 0;
}
















