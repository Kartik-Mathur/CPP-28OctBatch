#include <iostream>
using namespace std;

string arr[10] = {
	"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"
};

int main() {
	int n = 10;
	for (int i = 0; i < n; ++i)
	{
		cout << arr[i] << " length: " << arr[i].size() << endl;
	}
	cout << endl;

	string a = "Hello";
	string b = "World";

	cout << a << endl;
	a += (" " + b);
	cout << a << endl;
	cout << a.size() << endl;
	a = "Coding Blocks";

	for (int i = 0; i < a.size(); ++i)
	{
		cout << a[i] << " ";
	}
	cout << endl;



	return 0;
}
















