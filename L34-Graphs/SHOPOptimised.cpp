#include <iostream>
#include <queue>
using namespace std;

int Time[26][26];
bool visited[26][26] = {0};

int n, m, si, sj, di, dj;
int a[26][26];

int x[] = { -1, 0, +1, 0};
int y[] = {0, +1, 0, -1};

bool isValid(int i, int j) {
	if (i >= 0 and i<n and j >= 0 and j < m and a[i][j] != INT_MAX) return true;
	return false;
}


int solve() {

	for (int i = 0; i < 26; ++i)
	{
		for (int j = 0; j < 26; ++j)
		{
			Time[i][j] = INT_MAX;
		}
	}
	Time[si][sj] = 0;

	queue<pair<int, int > > q;
	q.push({si, sj});

	while (!q.empty()) {
		auto p = q.front();
		q.pop();
		int i = p.first;
		int j = p.second;

		for (int k = 0; k < 4; ++k)
		{
			int ni = i + x[k];
			int nj = j + y[k];
			if (isValid(ni, nj) and Time[ni][nj] > Time[i][j] + a[ni][nj]) {
				Time[ni][nj] = Time[i][j] + a[ni][nj];
				q.push({ni, nj});
			}
		}
	}
	return Time[di][dj];
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
		cout << solve() << endl;
		cin >> m >> n;
	}

	return 0;
}
















