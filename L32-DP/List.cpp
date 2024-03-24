#include <iostream>
#include <list>
using namespace std;

int main() {

	list<int> l;
	// list<int>::iterator it;

	l.push_back(1);
	l.push_back(2);
	l.push_back(3);
	l.push_back(4);
	// l.pop_back();
	// l.pop_front();
	l.push_front(5);
	l.push_front(6);

	auto it = l.begin();
	while (it != l.end()) {
		// cout << *it << "-->";
		if (*it == 1) break;
		it++;
	}
	l.insert(it, 100);
	// cout << endl;

	for (auto d : l) {
		cout << d << "-->";
	}
	cout << endl;



	return 0;
}

