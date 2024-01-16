#include <iostream>
using namespace std;

int main() {

	int a = 10;
	float f = 10.11;
	int arr[] = {1, 2, 3, 4};
	char ch = 'A';
	char *chp = &ch;

	cout << "Address of a: " << &a << endl;
	cout << "Address of f: " << &f << endl;
	cout << "a: " << a << endl;
	cout << "Array name arr: " << arr << endl;
	cout << "Address of arr[0]: " << &arr[0] << endl;
	cout << "Address of ch: " << &ch << endl;
	cout << "Value of chp: " << chp << endl;


	return 0;
}
















