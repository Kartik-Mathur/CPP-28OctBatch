#include <iostream>
#include <vector>
using namespace std;

int main() {

	vector<int> v;
	int n;
	cin >> n;

	v.resize(n); // N buckets create kr dega vector ke andar

	v.push_back(10);

	for (int i = 0; i < n; ++i)
	{
		v[i] = i + 1;
	}


	for (int i = 0; i < v.size(); ++i)
	{
		cout << v[i] << " ";
	}
	cout << endl;

	return 0;
}
















