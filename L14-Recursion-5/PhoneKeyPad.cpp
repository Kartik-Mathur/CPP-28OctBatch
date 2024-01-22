#include <iostream>
using namespace std;

char keys[][10] = {
	"", "", "ABC", "DEF", "GHI", "JKL", "MNO", "PQRS", "TUV", "WXYZ"
};

void phoneKeypad(char *in, int i, char* out, int j) {
	// base case
	if (!in[i]) {
		out[j] = '\0';
		cout << out << endl;
		return;
	}
	// recursive case
	int d = in[i] - '0';
	for (int k = 0; keys[d][k] != '\0'; ++k)
	{
		out[j] = keys[d][k];
		phoneKeypad(in, i + 1, out, j + 1);
	}
}

int main() {

	char a[100];
	cin >> a;
	char out[100];

	phoneKeypad(a, 0, out, 0);

	return 0;
}
















