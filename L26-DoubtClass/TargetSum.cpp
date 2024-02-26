#include <iostream>
using namespace std;

int main() {
	int n, target, cnt = 0;
	cin >> n >> target;
	int a[21];
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}

	for (int i = 0; i <= ((1 << n) - 1); ++i)
	{
		int x = i;

		int j = 0, ans = 0;
		while (j < n) {
			int val = (x & 1);
			x = x >> 1;
			if (val) {
				ans += a[j] * (-1);
			}
			else {
				ans += a[j] * (1);
			}
			j++;
		}
		cout << endl;

		if (ans == target) {
			cnt++;
		}
	}

	cout << cnt << endl;

	return 0;
}
















