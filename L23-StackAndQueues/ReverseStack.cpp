#include <iostream>
#include <stack>
using namespace std;

void pushAtBottom(stack<int> &s, int topElement) {
	// base case
	if (s.empty()) {
		s.push(topElement);
		return;
	}
	// recursive case
	int top = s.top();
	s.pop();
	pushAtBottom(s, topElement);
	s.push(top); // Vapis jaate wqt top element daalte chalo
}

void reverseStack(stack<int> &s) {
	// base case
	if (s.empty()) return;
	// recursive case
	int topElement = s.top();
	s.pop();
	reverseStack(s);
	pushAtBottom(s, topElement);
}

void printStack(stack<int> s) {
	while (!s.empty()) {
		cout << s.top() << " ";
		s.pop();
	}
	cout << endl;
}

int main() {

	stack<int> s;

	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);


	printStack(s);
	reverseStack(s);
	printStack(s);


	return 0;
}
















