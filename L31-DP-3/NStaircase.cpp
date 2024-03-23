#include <iostream>
using namespace std;

int nstairs(int n, int k, int *dp) {
	// base case
	if (!n) return dp[n] = 1;
	if (n < 0) return 0;

	if (dp[n] != -1) return dp[n];

	int ans = 0;
	for (int i = 1; i <= k; ++i)
	{
		ans += nstairs(n - i, k, dp);
	}
	return dp[n] = ans;
}

int bottomUp(int n, int k) {
	int dp[10000] = {0};
	dp[0] = 1;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= k; ++j)
		{
			dp[i] += (i - j >= 0) ? dp[i - j] : 0;
		}
	}
	for (int i = 0; i <= n; ++i)
	{
		cout << dp[i] << " ";
	}
	cout << endl;
	return dp[n];
}

int optimisedNstairs(int n, int k) {
	int dp[10000] = {0};
	dp[1] = dp[0] = 1;
	for (int i = 2; i <= n; ++i)
	{
		dp[i] = 2 * dp[i - 1] - ( (i - 1 - k) >= 0 ? dp[i - 1 - k] : 0 );
	}
	// for (int i = 0; i <= n; ++i)
	// {
	// 	cout << dp[i] << " ";
	// }
	// cout << endl;
	return dp[n];
}

int main() {

	int n, k = 3;
	cin >> n;
	int dp[10000];
	memset(dp, -1, sizeof dp);
	cout << nstairs(n, k, dp) << endl;
	cout << bottomUp(n, k) << endl;
	cout << optimisedNstairs(n, k) << endl;

	return 0;
}
















