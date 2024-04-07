#include <iostream>
#include <set>
using namespace std;

int main() {

	set<int> s;

	s.insert(1);
	s.insert(10);
	s.insert(2);
	s.insert(5);
	s.insert(3);

	auto x = s.find(12);
	if (x != s.end()) {
		cout << *x << endl;
	}
	else cout << "Not Found\n";

	while (!s.empty()) {
		cout << *s.begin() << " ";
		s.erase(s.begin());
	}
	cout << endl;

	// for (auto e : s) {
	// 	cout << e << " ";
	// }
	// cout << endl;
	// set<int> :: iterator it;
	// for (it = s.begin(); it != s.end() ; ++it)
	// {
	// 	cout << *it << " ";
	// }
	// cout << endl;

	return 0;
}
















