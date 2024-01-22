#include <iostream>
#include <vector>
using namespace std;

int nstairs(int n) {
	// base case
	if (n == 0) return 1;
	if (n < 0) return 0;
	// recursive case
	return nstairs(n - 1) + nstairs(n - 2) + nstairs(n - 3);
}

int stairs(int n, int k) {
	// base case
	if (n == 0) return 1;
	if (n < 0) return 0;
	// recursive case
	// int ans = stairs(n - 1) + stairs(n - 2) + .. + stairs(n - k);
	int ans = 0;
	for (int i = 1; i <= k; ++i)
	{
		ans += stairs(n - i, k);
	}
	return ans;
}
void printWays(int n, int *a, int s, int &cnt) {
	if (n == 0) {
		cnt++;
		for (int i = 0; i < s; ++i)
		{
			cout << a[i] << " ";
		}
		cout << endl;
		return;
	}

	if (n < 0) return;

	a[s] = 1;
	printWays(n - 1, a, s + 1, cnt);
	a[s] = 2;
	printWays(n - 2, a, s + 1, cnt);
	a[s] = 3;
	printWays(n - 3, a, s + 1, cnt);
}

int main() {

	int n;
	cin >> n;

	cout << nstairs(n) << endl;
	cout << stairs(n, 3) << endl;
	int a[100];
	int cnt = 0;
	printWays(n, a, 0, cnt);
	cout << "No of ways: " << cnt << endl;



	return 0;
}
















