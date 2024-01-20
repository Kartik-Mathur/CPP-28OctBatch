#include <iostream>
using namespace std;
// ANAGRAM

void subsequences(char*in, int i, char*out, int j) {
	// base case
	if (in[i] == '\0') {
		out[j] = '\0';
		cout << out << endl;
		return;
	}
	// recursive case
	// 1. pehle ith character ko ignore kardo
	subsequences(in, i + 1, out, j);

	// 2. ith character ko include krlo
	out[j] = in[i];
	subsequences(in, i + 1, out, j + 1);

}

int main() {

	char a[] = "abc";
	char out[100];

	subsequences(a, 0, out, 0);


	return 0;
}
















