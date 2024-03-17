#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

#define vi vector<int>
#define mk(arr,n,v) int *arr = new int[n + 1]; for (int i = 0; i <= n; ++i){arr[i] = v;}

int wineProblem(int *wine, int l, int r, int day) {
	// base case
	if (l > r) return 0;

	// recursive case
	int op1 = wine[l] * day + wineProblem(wine, l + 1, r, day + 1);
	int op2 = wine[r] * day + wineProblem(wine, l, r - 1, day + 1);
	return max(op1, op2);
}

int wineProblem1(int *wine, int l, int r, int n) {
	// base case
	if (l > r) return 0;

	// recursive case
	int day = n - (r - l);
	int op1 = wine[l] * day + wineProblem1(wine, l + 1, r, n);
	int op2 = wine[r] * day + wineProblem1(wine, l, r - 1, n);
	return max(op1, op2);
}


int topDown(int *wine, int l, int r, int day, int dp[][100]) {
	// base case
	if (l > r) return dp[l][r] = 0;

	if (dp[l][r] != -1) return dp[l][r];

	// recursive case
	int op1 = wine[l] * day + topDown(wine, l + 1, r, day + 1, dp);
	int op2 = wine[r] * day + topDown(wine, l, r - 1, day + 1, dp);
	return dp[l][r] = max(op1, op2);
}

int bottomUp(int *wine, int n) {
	int dp[100][100] = {0};
	for (int i = n - 1; i >= 0; --i)
	{
		for (int j = i; j < n; ++j)
		{
			int cd = n - (j - i);
			int op1 = cd * wine[i] +
			          (i + 1 < n ? dp[i + 1][j] : 0);

			int op2 = cd * wine[j] +
			          (j - 1 >= 0 ? dp[i][j - 1] : 0);
			dp[i][j] = max(op1, op2);
		}
	}

	return dp[0][n - 1];
}


int main() {

	int wine[] = {2, 3, 5, 1, 4};
	int n = sizeof(wine) / sizeof(int);

	int dp[100][100];
	memset(dp, -1, sizeof dp);

	cout << wineProblem(wine, 0, n - 1, 1) << endl;
	cout << wineProblem1(wine, 0, n - 1, n) << endl;
	cout << topDown(wine, 0, n - 1, 1, dp) << endl;
	cout << bottomUp(wine, n) << endl;

	// for (int i = 0; i < n; ++i)
	// {
	// 	for (int j = 0; j < n; ++j)
	// 	{
	// 		cout << dp[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }

	return 0;
}
















