#include <iostream>
#include <vector>
using namespace std;

vector<vector<int> > ans;

void printLIS(int *dp, int indx, vector<int> &v,
              int last_element, int *a, int lis_remaining) {
	// base case

	if (lis_remaining == 0) {
		for (auto x : v) {
			cout << x << " ";
		}
		cout << endl;
		return;
	}
	if (indx == -1) return;

	// recursive case
	// 1. current indx wale ko include karlo and last_element>=a[indx]
	if (last_element >= a[indx] and lis_remaining == dp[indx]) {
		v.push_back(a[indx]);
		printLIS(dp, indx - 1, v, a[indx], a, lis_remaining - 1);
		v.pop_back();
	}
	// 2. Include mat karo
	printLIS(dp, indx - 1, v, last_element, a, lis_remaining);
}

int LIS(int *a, int n) {
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

	int mx_lis = 0, indx;
	for (int i = 0; i < n; ++i)
	{
		if (mx_lis <= dp[i]) {
			mx_lis = dp[i];
			indx = i;
		}
	}
	vector<int> v;
	printLIS(dp, indx, v, INT_MAX, a, mx_lis);
	return mx_lis;
}

int FindLIS(int *a, int n) {
	int dp[10000];
	for (int i = 0; i <= n; ++i) dp[i] = 1;

	for (int i = 1; i < n; ++i)
	{
		for (int j = i - 1; j >= 0; --j)
		{
			if (a[i] >= a[j]) {
				// agr dp[j]+1 bada hai dp[i] se
				if (dp[j] + 1 > dp[i]) {
					vector<int> x = ans[j];
					x.push_back(a[i]);
					ans[i] =  x;
					dp[i] = dp[j] + 1;
				}
			}
		}
	}

	int mx_lis = 0, indx;
	for (int i = 0; i < n; ++i)
	{
		if (mx_lis < dp[i]) {
			mx_lis = dp[i];
			indx = i;
		}
	}
	for (auto v : ans[indx]) {
		cout << v << " ";
	}
	cout << endl;
	return mx_lis;
}



int main() {
	int t;
	cin >> t;

	int a[] = {2, 4, 1, 6, 3, 7, 11, 8};
	int n = sizeof(a) / sizeof(int);

	for (int i = 0; i < n; ++i)
	{
		ans.push_back({a[i]});
	}
	cout << LIS(a, n) << endl;
	// cout << FindLIS	(a, n) << endl;



	return 0;
}
















