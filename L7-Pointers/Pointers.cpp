#include <iostream>
using namespace std;

int main() {

	int *ap, *cp, *bp;
	ap = bp = cp = NULL; //  NULL ka matlab zero value

	// ap, bp, and cp are integer pointers
	int a = 10;
	ap = &a;

	cout << *bp << endl;

	cout << "ap: " << ap << endl;
	cout << "ap+1: " << ap + 1 << endl;

	return 0;
}
















