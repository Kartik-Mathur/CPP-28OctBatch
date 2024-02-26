#include <iostream>
#include <vector>
using namespace std;

#define ll long long

int main() {

	ll n;
	cin >> n;
	vector<ll> a(n);
	for (ll i = 0; i < n; ++i)
	{
		cin >> a[i];
	}

	vector<ll> leftMax(n), rightMax(n);

	ll cmax = 0;
	for (ll i = 0; i < n; ++i)
	{
		leftMax[i] = cmax;
		cmax = max(cmax, a[i]);
	}

	cmax = 0;
	for (ll i = n - 1; i >= 0; --i)
	{
		rightMax[i] = cmax;
		cmax = max(cmax, a[i]);
	}

	ll ans = 0;
	for (ll i = 0; i < n; ++i)
	{
		if (min(leftMax[i], rightMax[i]) - a[i] > 0) {
			ans += (min(leftMax[i], rightMax[i]) - a[i] );
		}
	}

	cout << ans << endl;



	return 0;
}
















