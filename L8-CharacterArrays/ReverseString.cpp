#include <iostream>
using namespace std;

void reverseString(char* a) {
	int i = 0, j = strlen(a) - 1;
	while (i < j) {
		swap(a[i], a[j]);
		i++;
		j--;
	}
}


int main() {

	char a[] = "Coding";

	reverseString(a);

	cout << "After: " << a << endl;

	return 0;
}
















