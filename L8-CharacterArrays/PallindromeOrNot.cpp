#include <iostream>
#include <cstring>
using namespace std;

bool isPallindrome(char *a) {
	int i = 0, j = strlen(a) - 1;

	while (i < j) {
		if (a[i] != a[j]) return false;
		i++;
		j--;
	}
	return true;
}

int main() {

	char a[] = "abbaa";

	if (isPallindrome(a)) {
		cout << "Pallindrome\n";
	}
	else {
		cout << "Not a Pallindrome\n";
	}

	return 0;
}
















