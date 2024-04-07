#include <iostream>
using namespace std;
int n, m, si, sj, di, dj;
int a[26][26];

int x[] = { -1, 0, +1, 0};
int y[] = {0, +1, 0, -1};

bool isValid(int i, int j, bool visited[][26]) {
	if (i >= 0 and i<n and j >= 0 and j < m and a[i][j] != INT_MAX
	        and visited[i][j] == false) return true;
	return false;
}

int solve(int si, int sj, int di, int dj, int dp[][26]) {
	// base case
	if (si == di and sj == dj) {
		return 0;
	}
	// recursive case
	// Mark the current cell as visited
	visited[si][sj] = true;
	int ans = INT_MAX;
	for (int k = 0; k < 4; ++k)
	{
		int ni = si + x[k];
		int nj = sj + y[k];
		if (isValid(ni, nj, visited)) {
			int chotiProb = solve(ni, nj, di, dj, dp);
			if (chotiProb != INT_MAX)
				ans = min(ans, chotiProb + a[si][sj]);
		}
	}

	visited[si][sj] = false; // Backtracking
	return ans;
}

int main() {

	cin >> m >> n;
	while (n and m) {

		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				char ch; cin >> ch;
				if (ch == 'X') {
					a[i][j] = INT_MAX;
				}
				else if (ch == 'S') {
					si = i; sj = j;
					a[i][j] = 0;
				}
				else if (ch == 'D') {
					di = i; dj = j;
					a[i][j] = 0;
				}
				else {
					a[i][j] = ch - '0';
				}
			}
		}
		bool visited[26][26] = {0};
		cout << solve(si, sj, di, dj, visited) << endl;
	}


	return 0;
}














