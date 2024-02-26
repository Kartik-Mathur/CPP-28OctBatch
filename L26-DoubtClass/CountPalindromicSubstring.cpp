#include <iostream>
using namespace std;

bool isPalindrome(char *a, int i, int j) {
	while (i < j) {
		if (a[i] != a[j]) return false;
		i++;
		j--;
	}
	return true;
}

int main() {
	// Way-2
	char a[10000];
	cin >> a;
	int i, j, k, cnt = 0;
	for (int k = 0; a[k] != '\0' ; ++k)
	{
		i = j = k;

		while (i >= 0 and a[j] != '\0' and a[i] == a[j]) {
			cnt ++;
			// cout << "Palindromic substring: ";
			// for (int l = i; l <= j ; ++l)
			// {
			// 	cout << a[l];
			// }
			// cout << endl;

			i--;
			j++;


		}
	}

	for (int k = 0; a[k] != '\0' ; ++k)
	{
		i = k;
		j = k + 1;

		while (i >= 0 and a[j] != '\0' and a[i] == a[j]) {
			cnt ++;
			// cout << "Palindromic substring: ";
			// for (int l = i; l <= j ; ++l)
			// {
			// 	cout << a[l];
			// }
			// cout << endl;

			i--;
			j++;


		}
	}

	cout << cnt << endl;

	// Way -1

	// char a[1000];
	// cin >> a;
	// int cnt = 0;
	// for (int i = 0; a[i] != '\0'; ++i)
	// {
	// 	for (int j = i; a[j] != '\0'; ++j)
	// 	{
	// 		if (isPalindrome(a, i, j)) {
	// 			cnt++;
	// 		}
	// 	}
	// }

	// cout << cnt ;


	return 0;
}
















