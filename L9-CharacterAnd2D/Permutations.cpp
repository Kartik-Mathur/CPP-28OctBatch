#include <iostream>
using namespace std;

void printABC() {
	char ch = 'a';
	for (int i = 0; i < 26; ++i)
	{
		cout << ch << " ";
		ch++;
	}
	cout << endl;
}

void printArray(int *a, int n) {
	for (int i = 0; i < n; ++i)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}

bool checkPermutations(int *a, int n) {
	for (int i = 0; i < n; ++i)
	{
		if (a[i] != 0) return false;
	}

	return true;
}

int main() {

	char a[] = "abcdaz";
	char b[] = "zaadcbj";
	int freq[26] = {0};

	for (int i = 0; a[i] != '\0'; ++i)
	{
		int indx = a[i] - 'a';
		freq[indx]++;
	}
	// printArray(freq, 26);
	// printABC();
	for (int i = 0; b[i] != '\0'; ++i)
	{
		int indx = b[i] - 'a';
		freq[indx]--;
	}
	// printArray(freq, 26);

	bool ans = checkPermutations(freq, 26);
	if (ans == true) {
		cout << "Permuations hai: " << a << " and " << b << endl;
	}
	else {
		cout << "Permuations nahi hai: " << a << " and " << b << endl;
	}

	return 0;
}
















