#include <iostream>
using namespace std;

int main() {

	int a[] = {1, 2, 3, 4, 5};
	int n = sizeof(a) / sizeof(int);

	cout << "&a[0]: " << &a[0] << endl;
	cout << "&a[1]: " << &a[1] << endl;
	cout << "&a[2]: " << &a[2] << endl;
	cout << "&a[3]: " << &a[3] << endl;
	cout << "&a[3]-&a[0]: " << &a[3] - &a[0] << endl;


	return 0;
}
















