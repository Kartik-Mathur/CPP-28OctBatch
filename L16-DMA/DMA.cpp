#include <iostream>
using namespace std;

int main() {

	int *a = new int;
	float *f = new float;



	*a = 10;
	*f = 1.11;

	cout << *a << endl;
	cout << *f << endl;

	delete a;
	a = NULL;
	delete f;
	f = NULL;

	return 0;
}
















