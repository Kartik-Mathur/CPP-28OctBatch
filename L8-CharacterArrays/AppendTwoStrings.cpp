#include <iostream>
using namespace std;

void concat(char* a, char *b) {
	int i = strlen(a);
	int lenb = strlen(b);

	for (int j = 0; j <= lenb; ++j)
	{
		a[i] = b[j];
		i++;
	}
}

int main() {

	char a[100] = "Hello";
	char b[] = "World";

	// concat(a, b);
	strcat(a, b);
	cout << a << endl;


	return 0;
}
















