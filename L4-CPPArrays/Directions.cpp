#include <iostream>
using namespace std;

int main() {

	int x = 0, y = 0;

	char ch;

	ch = cin.get();

	while (ch != '\n') {
		if (ch == 'N') {
			y++;
		}
		else if (ch == 'S') {
			y--;
		}
		else if (ch == 'E') {
			x++;
		}
		else if (ch == 'W') {
			x--;
		}

		ch = cin.get();
	}

	cout << x << ", " << y << endl;

	if (x >= 0 and y >= 0) {
		// 1st quad: print x times 'E', y times 'N'
		for (int i = 0; i < x; ++i)
		{
			cout << 'E';
		}

		for (int i = 0; i < y; ++i)
		{
			cout << 'N';
		}
	}
	else if (x <= 0 and y >= 0) {
		// 2nd quad: print y times 'N', x times 'W'
		x = x * -1;
		for (int i = 0; i < y; ++i)
		{
			cout << 'N';
		}

		for (int i = 0; i < x; ++i)
		{
			cout << 'W';
		}
	}
	else if (x <= 0 and y <= 0) {
		// 3rd quad: print y times 'S', x times 'W'
		x = x * -1;
		y = y * -1;

		for (int i = 0; i < y; ++i)
		{
			cout << 'S';
		}

		for (int i = 0; i < x; ++i)
		{
			cout << 'W';
		}
	}
	else {
		// 4th quad: print x times 'E', y times 'S'
		y = y * -1;
		for (int i = 0; i < x; ++i)
		{
			cout << 'E';
		}

		for (int i = 0; i < y; ++i)
		{
			cout << 'S';
		}
	}

	return 0;
}
















