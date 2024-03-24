#include <iostream>
using namespace std;

int main() {

	int n, m; cin >> n >> m;
	int dp[1000][1000];

	for (int i = 0; i <= n; ++i)
	{
		for (int j = 0; j <= m; ++j)
		{
			if (i == 0 and j == 0) dp[i][j] = 1;
			else if ( i == 0 || j == 0) dp[i][j] = 1;
			else {
				dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
			}
		}
	}

	for (int i = 0; i <= n; ++i)
	{
		for (int j = 0; j <= m; ++j)
		{
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}


	return 0;
}
















