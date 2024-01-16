#include <iostream>
using namespace std;

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

	char a[] = "AabcdazXZj@";
	char b[] = "za@adZAcbjX";

	int freq[256] = {0};

	for (int i = 0; a[i] != '\0'; ++i)
	{
		int indx = a[i];
		freq[indx]++;
	}

	for (int i = 0; b[i] != '\0'; ++i)
	{
		int indx = b[i];
		freq[indx]--;
	}

	bool ans = checkPermutations(freq, 256);
	if (ans == true) {
		cout << "Permuations hai: " << a << " and " << b << endl;
	}
	else {
		cout << "Permuations nahi hai: " << a << " and " << b << endl;
	}

	return 0;
}
















