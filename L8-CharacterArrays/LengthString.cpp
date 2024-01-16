#include <iostream>
#include <cstring>
using namespace std;

int lengthStr(char *a) {
	int i;
	for (i = 0; a[i] != '\0'; ++i)
	{

	}
	return i;
}

int main() {

	char a[] = "Hello World";

	// User defined function
	cout << lengthStr(a) << endl;
	// Inbuilt alternativ
	cout << strlen(a) << endl;
	return 0;
}
















