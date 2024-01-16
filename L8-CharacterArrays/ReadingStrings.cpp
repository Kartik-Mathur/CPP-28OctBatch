#include <iostream>
using namespace std;

void inputString(char *a, int n, char x = '\n') {
	char ch;
	int i = 0;

	ch = cin.get();
	while (ch != x and i < n - 1) {
		a[i] = ch;
		i++;

		ch = cin.get();
	}
	a[i] = '\0';
}

int main() {

	char a[100];
	// cin >> a;
	// inputString(a, 100);
	int x;
	cin >> x;
	cin.get(); // Ek character ko read karo and store mat karo
	// ignore ho jaega

	cin.getline(a, 100);

	cout << "String is: " << a << endl;

	return 0;
}
















