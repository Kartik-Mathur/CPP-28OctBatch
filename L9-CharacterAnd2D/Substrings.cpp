#include <iostream>
using namespace std;

int main() {

	char a[] = "abc";
	int n = strlen(a);

	for (int i = 0; i < n; ++i)
	{
		for (int j = i; j < n; ++j)
		{
			for (int k = i; k <= j; ++k)
			{
				cout << a[k];
			}
			cout << endl;
		}
	}

	return 0;
}
















