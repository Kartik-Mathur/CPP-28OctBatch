#include <iostream>
using namespace std;

int main() {

	char a;
	int cnt = 0;

	cin >> a;
	while (a != '$') {

		// cout << a << endl;
		cnt++;

		cin >> a;
	}
	cout << "You have entered: " << cnt << endl;
	return 0;
}















