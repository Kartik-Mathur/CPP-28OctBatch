#include <iostream>
using namespace std;
/*
bool check7(int *a, int n, int i) {
	// base case
	if (i == n) {
		return false;
	}

	// recursive case
	if (a[i] == 7) {
		return true;
	}

	bool choteMei7 = check7(a, n, i + 1);
	if (choteMei7 == true) {
		return true;
	}
	else {
		return false;
	}
}
*/

bool check7(int *a, int n, int i) {
	// base case
	if (i == n) {
		return false;
	}

	// recursive case
	if (a[i] == 7) {
		return true;
	}

	return check7(a, n, i + 1);
}

int first7(int *a, int n, int i) {
	// base case
	if (i == n) {
		return -1;
	}

	// recursive case
	if (a[i] == 7) {
		return i;
	}

	return first7(a, n, i + 1);
}

int last7(int *a, int i) {
	// base case
	if (i == -1) {
		return -1;
	}
	// recursive case
	if (a[i] == 7) {
		return i;
	}
	return last7(a, i - 1);
}

void printAll7(int *a, int n, int i) {
	// base case
	if (i == n) {
		return ; // base case se return ho jaana simply
	}

	if (a[i] == 7) {
		cout << i << " ";
	}

	printAll7(a, n, i + 1);
}

int main() {

	int a[] = {70, 2, 3, 7, 4, 5, 7, 7, 6};
	int n = sizeof(a) / sizeof(int);

	if (check7(a, n, 0) == true) {
		cout << "7 present hai\n";
	}
	else {
		cout << "7 present nahi hai\n";
	}

	cout << first7(a, n, 0) << endl;
	cout << last7(a, n - 1) << endl;
	printAll7(a, n, 0);
	cout << endl;

	return 0;
}
















