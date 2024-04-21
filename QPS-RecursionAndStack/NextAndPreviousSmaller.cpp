#include <iostream>
#include <stack>
using namespace std;

int main() {

	int heights[] = {1, 5, 3, 0, 2, 6, 8, 9, 4};
	int n = sizeof(heights) / sizeof(int);

	int ns[1000], ps[1000];

	stack<int> s;
	ns[n - 1] = -1;
	s.push(n - 1);
	for (int i = n - 2; i >= 0; --i)
	{
		int currentHeight = heights[i];
		while (!s.empty() and currentHeight < heights[s.top()]) {
			s.pop();
		}

		s.empty() ? ns[i] = -1 : ns[i] = s.top();
		s.push(i);
	}
	while (!s.empty()) s.pop();

	ps[0] = -1;
	s.push(0);
	for (int i = 1; i < n; ++i)
	{
		int currentHeight = heights[i];
		while (!s.empty() and currentHeight < heights[s.top()]) {
			s.pop();
		}

		s.empty() ? ps[i] = -1 : ps[i] = s.top();
		s.push(i);
	}

	for (int i = 0; i < n; ++i)
	{
		cout << heights[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < n; ++i)
	{
		ns[i] != -1 ?
		cout << heights[ns[i]] << " " : cout << '$' << " ";
	}
	cout << endl;

	for (int i = 0; i < n; ++i)
	{
		ps[i] != -1 ?
		cout << heights[ps[i]] << " " : cout <<  '$' << " ";
	}
	cout << endl;

	return 0;
}
















