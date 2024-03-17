#include <iostream>
using namespace std;
#define mk(arr,n,v) int *arr = new int[n + 1]; for (int i = 0; i <= n; ++i){arr[i] = v;}

int fibo(int n) {
	// base case
	if (n <= 1) return n;
	// recursive case
	return fibo(n - 1) + fibo(n - 2);
}

int topDown(int n, int *dp) {
	if (n <= 1) {
		return dp[n] = n;
	}

	if (dp[n] != -1) return dp[n];

	return dp[n] = topDown(n - 1, dp) + topDown(n - 2, dp);
}

int bottomUp(int n) {
	int* dp = new int[n + 1];
	dp[0] = 0;
	dp[1] = 1;

	for (int i = 2; i <= n; ++i)
	{
		dp[i] = dp[i - 1] + dp[i - 2];
	}

	return dp[n];
}

int main() {

	int n; cin >> n;
	mk(dp, n, -1);

	// int arr[100001];
	// for (int i = 0; i <= 100000; ++i)
	// {
	// 	arr[i] = -1;
	// }


	cout << topDown(n, dp) << endl;

	cout << bottomUp(n) << endl;
	cout << fibo(n) << endl;

	return 0;
}
















