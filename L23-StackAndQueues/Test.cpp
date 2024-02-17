#include <iostream>
#include <stack>
using namespace std;

bool isBalanced(char*a) {
	stack<char> s;

	for (int i = 0; a[i] != '\0'; ++i)
	{
		char ch = a[i];
		switch (ch) {
		case '[':
		case '{':
		case '(':
			s.push(ch);
			break;

		case ')':
			if (!s.empty() and s.top() == '(') {
				s.pop();
			}
			else {
				return false;
			}
			break;

		case ']':
			if (!s.empty() and s.top() == '[') {
				s.pop();
			}
			else {
				return false;
			}
			break;
		case '}':
			if (!s.empty() and s.top() == '{') {
				s.pop();
			}
			else {
				return false;
			}
			break;
		}
	}

	if (s.empty()) return true;
	else return false;
}

int main() {

	char a[] = "[a*(b+c)+{x+y*(z+w)}]";

	if (isBalanced(a)) {
		cout << "Balanced Paranthesis\n";
	}
	else {
		cout << "Not Balanced Paranthesis\n";
	}


	return 0;
}
















