#include <iostream>
using namespace std;

int main() {

	int a[] = {10, 9, 3, 5, 4, 11, 7, 8};
	int n = sizeof(a) / sizeof(int);

	int dp[10000];
	for (int i = 0; i <= n; ++i) dp[i] = 1;

	for (int i = 1; i < n; ++i)
	{
		for (int j = i - 1; j >= 0; --j)
		{
			if (a[i] >= a[j]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < n; ++i)
	{
		ans = max(ans, dp[i]);
	}
	cout << ans << endl;

	return 0;
}
















