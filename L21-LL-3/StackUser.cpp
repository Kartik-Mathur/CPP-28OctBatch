#include <iostream>
#include <vector>
using namespace std;

template<typename T>
class Stack {
private:
	vector<T> v;
public:

	void push(T d) {
		v.push_back(d);
	}

	void pop() {
		v.pop_back();
	}

	bool empty() {
		return v.size() == 0;
	}

	T top() {
		return v[v.size() - 1];
	}

};

int main() {


	Stack<char> s;

	s.push('A');
	s.push('B');
	s.push('C');
	s.push('D');

	// s.push(1);
	// s.push(2);
	// s.push(3);
	// s.push(4);

	while (!s.empty()) {
		cout << s.top() << " ";
		s.pop();
	}

	cout << endl;

	return 0;
}
















