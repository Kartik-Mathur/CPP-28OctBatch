#include <iostream>
using namespace std;

// void: Jab kch return nhi krna hota then we use void
void helloWorld() {
	cout << "Hello World\n";
}

void printSum(int a, int b) {
	cout << "Sum: " << a + b << endl;
}

int add(int a, int b) {
	return a + b;
}

void checkEven(int a) {
	if (a % 2 == 0) {
		cout << "Sum is Even\n";
	}
	else {
		cout << "Sum is Odd\n";
	}
}

int main() {

	helloWorld();// invoking

	int a = 10;
	int b = 20;

	int sum = add(a, b);
	checkEven(sum);

	sum = add(30, 40);
	checkEven(sum);
	// printSum(a, b);



	return 0; // Success
}
















