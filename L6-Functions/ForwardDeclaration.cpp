#include <iostream>
using namespace std;

void helloWorld(); // Function declaration ko upar krdo
// int add(int a, int b);
int add(int, int);

int main() {

	helloWorld();
	cout << add(10, 20) << endl;

	return 0;
}

void helloWorld() {
	cout << "Hello World\n";
}

int add(int a, int b) {
	return a + b;
}



