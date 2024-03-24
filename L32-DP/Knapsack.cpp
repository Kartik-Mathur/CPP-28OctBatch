#include <iostream>
#include <cstring>
using namespace std;


int knapsack(int *price, int *wt, int capacity, int n) {
	// base case
	if (n == 0 || capacity == 0) {
		return 0;
	}

	// recursive case
	int op1, op2;
	op1 = op2 = INT_MIN;
	if (capacity >= wt[n - 1]) {
		op1 = price[n - 1] + knapsack(price, wt, capacity - wt[n - 1], n - 1);
	}
	op2 = 0 + knapsack(price, wt, capacity, n - 1);
	return max(op1, op2);
}

int topDown(int *price, int *wt, int capacity, int n, int dp[][100]) {
	// base case
	if (n == 0 || capacity == 0) {
		return dp[n][capacity] = 0;
	}
	if (dp[n][capacity] != -1) return dp[n][capacity];
	// recursive case
	int op1, op2;
	op1 = op2 = INT_MIN;
	if (capacity >= wt[n - 1]) {
		op1 = price[n - 1] + topDown(price, wt, capacity - wt[n - 1], n - 1, dp);
	}
	op2 = 0 + topDown(price, wt, capacity, n - 1, dp);
	return dp[n][capacity] = max(op1, op2);
}

int bottomUp(int *price, int *wt, int capacity, int N) {
	int dp[100][100] = {0};
	for (int n = 1; n <= N; ++n)
	{
		for (int c = 1; c <= capacity; ++c)
		{
			int op1, op2;
			op1 = op2 = INT_MIN;
			if (wt[n - 1] <= c) {
				op1 = price[n - 1] + dp[n - 1][c - wt[n - 1]];
			}
			op2 = dp[n - 1][c];
			dp[n][c] = max(op1, op2);
		}
	}
	return dp[N][capacity];
}

int main() {
	int price[] = {4, 5, 6, 3};
	int wt[] = {2, 3, 3, 2};
	int n = sizeof(price) / sizeof(int), capacity = 5;
	int dp[100][100];
	memset(dp, -1, sizeof dp);

	cout << knapsack(price, wt, capacity, n) << endl;
	cout << topDown(price, wt, capacity, n, dp) << endl;
	cout << bottomUp(price, wt, capacity, n) << endl;





	return 0;
}
















