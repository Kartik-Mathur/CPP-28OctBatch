#include <iostream>
#include <vector>
using namespace std;

#define vi vector<int>
#define mk(arr,n,v) int *arr = new int[n + 1]; for (int i = 0; i <= n; ++i){arr[i] = v;}

int coinExchange(int amount, int *deno, int n, vi &v) {
	// base case
	if (amount == 0) {
		// for (int value : v) {
		// 	cout << value << " ";
		// }
		// cout << endl;
		return 0;
	}

	// recursive case
	int ans = INT_MAX;
	for (int i = 0; i < n; ++i)
	{
		if (amount >= deno[i]) {
			int chotiAmt = amount - deno[i];
			v.push_back(deno[i]);
			int x = coinExchange(chotiAmt, deno, n, v);
			v.pop_back(); // backtracking
			if (x != INT_MAX) ans = min(ans, x + 1);
		}
	}

	return ans;
}

int topDown(int amount, int *deno, int n, int*dp) {
	// base case
	if (amount == 0) {
		return dp[amount] = 0;
	}

	// Check karlo bhai already toh nahi calculate kia hua amount ka answer
	if (dp[amount] != -1) return dp[amount];

	// recursive case
	int ans = INT_MAX;
	for (int i = 0; i < n; ++i)
	{
		if (amount >= deno[i]) {
			int chotiAmt = amount - deno[i];
			int x = topDown(chotiAmt, deno, n, dp);
			if (x != INT_MAX) ans = min(ans, x + 1);
		}
	}

	return dp[amount] = ans;
}

int bottomUp(int finalAmount, int *deno, int n) {
	mk(dp, finalAmount, INT_MAX);

	dp[0] = 0;

	for (int amount = 0; amount <= finalAmount; ++amount)
	{
		for (int i = 0; i < n; ++i)
		{
			if (amount >= deno[i]) {
				int chotiAmt = amount - deno[i];
				if (dp[chotiAmt] != INT_MAX) {
					dp[amount] = min(dp[amount], dp[chotiAmt] + 1);
				}
			}
		}
	}

	for (int i = 0; i <= finalAmount; ++i)
	{
		cout << dp[i] << " ";
	}
	cout << endl;
	return dp[finalAmount];
}

int main() {

	int deno[] = {3, 4, 7};
	int n = sizeof(deno) / sizeof(int);
	int amount;
	cin >> amount;
	mk(dp, amount, -1);

	vi v;
	cout << topDown(amount, deno, n, dp) << endl;
	cout << bottomUp(amount, deno, n) << endl;
	cout << coinExchange(amount, deno, n, v) << endl;


	return 0;
}
















