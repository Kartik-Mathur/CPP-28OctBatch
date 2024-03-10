#include <iostream>
using namespace std;

int main() {

	int s = 7;

	// cout << INT_MIN << endl;
	// cout << INT_MIN - 1 << endl;
	cout << 27 * 27 << endl;
	cout << (27 * 27 * 27) % 7 << endl;
	// cout << ( ( ( (27 % 7) * (27 % 7) ) % 7 ) * 27 ) % 7 << endl;
	int ans = 1;
	for (int i = 0; i < 3; ++i)
	{
		ans = (ans % 7) * (27 % 7);
		ans = ans % 7;
	}
	cout << ans << endl;

	return 0;
}
















