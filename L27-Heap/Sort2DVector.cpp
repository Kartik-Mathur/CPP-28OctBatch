#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool mycompare(vector<int> &a, vector<int> &b) {
	if (a[0] == b[0]) {
		return a[1] < b[1];
	}
	return a[0] < b[0];
}

int main() {

	vector<vector<int> > v = {
		{0, 30},  {15, 20}, {5, 10}, {0, 4}
	};

	sort(v.begin(), v.end(), mycompare);

	for (int i = 0; i < v.size(); ++i)
	{
		cout << v[i][0] << ", " << v[i][1] << endl;
	}

	return 0;
}
















