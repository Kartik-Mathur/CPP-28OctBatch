#include <iostream>
using namespace std;

int main() {
	char ch;
	int cnt = 0;

	ch = cin.get();

	while (ch != '$') {

		// cout << a << endl;
		cnt++;

		ch = cin.get();
	}
	cout << "You have entered: " << cnt << endl;

	return 0;
}
















