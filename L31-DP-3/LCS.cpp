#include <iostream>
using namespace std;

int lcs(string &s1, string &s2, int i, int j) {
	// base case
	if ( i == 0 || j == 0) return 0;
	// recursive case
	if (s1[i - 1] == s2[j - 1]) return 1 + lcs(s1, s2, i - 1, j - 1);
	return max(lcs(s1, s2, i, j - 1), lcs(s1, s2, i - 1, j));
}

int topDown(string &s1, string &s2, int i, int j, int dp[][100]) {
	// base case
	if ( i == 0 || j == 0) return dp[i][j] = 0;

	if (dp[i][j] != -1) return dp[i][j];
	// recursive case
	if (s1[i - 1] == s2[j - 1])
		return dp[i][j] = 1 + topDown(s1, s2, i - 1, j - 1, dp);

	return dp[i][j] = max (topDown(s1, s2, i, j - 1, dp),
	                       topDown(s1, s2, i - 1, j, dp));
}

void printLCS(const string &s1, const string &s2, int dp[][1000],
              int m, int n, string &x) {
	// base case
	if (m == 0 and n == 0) {
		reverse(x.begin(), x.end());
		cout << x << endl;
		return;
	}

	// recursive case
	if (s1[m - 1] == s2[n - 1]) {
		x.push_back(s1[m - 1]);
		printLCS(s1, s2, dp, m - 1, n - 1, x);
		x.pop_back();
	}
	else {
		if (dp[m - 1][n] == dp[m][n]) printLCS(s1, s2, dp, m - 1, n, x);
		if (dp[m][n - 1] == dp[m][n]) printLCS(s1, s2, dp, m, n - 1, x);
	}
}

int bottomUp(const string &s1, const string &s2) {
	int dp[1000][1000] = {0};

	for (int i = 1; i <= s1.size(); ++i)
	{
		for (int j = 1; j <= s2.size(); ++j)
		{
			if (s1[i - 1] == s2[j - 1]) dp[i][j] = 1 + dp[i - 1][j - 1];
			else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}
	string x = "";
	printLCS(s1, s2, dp, s1.size(), s2.size(), x);
	return dp[s1.size()][s2.size()];
}

int main() {

	string s1 = "abcde";
	string s2 = "abced";
	int t;
	cin >> t;
	int dp[100][100];
	memset(dp, -1, sizeof dp);
	cout << lcs(s1, s2, s1.size(), s2.size()) << endl;
	cout << topDown(s1, s2, s1.size(), s2.size(), dp) << endl;
	cout << bottomUp(s1, s2) << endl;

	// for (int i = 0; i <= s1.size(); ++i)
	// {
	// 	for (int j = 0; j <= s2.size(); ++j)
	// 	{
	// 		cout << dp[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }



	return 0;
}
















