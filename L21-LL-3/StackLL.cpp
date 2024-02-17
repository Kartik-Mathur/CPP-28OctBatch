#include <iostream>
using namespace std;

template<typename U>
class node {
public:
	U data;
	node<U> * next;
	node(U d) {
		data  = d;
		next = NULL;
	}
};

template<typename T>
class Stack {
	node<T> *head;
public:
	Stack() {
		head = NULL;
	}

	void push(T d) {
		if (head == NULL) {
			head = new node<T>(d);
		}
		else {
			node<T>* n = new node<T>(d);
			n->next = head;
			head = n;
		}
	}

	void pop() {
		if (head->next == NULL) {
			delete head;
			head = NULL;
			return;
		}

		node<T>* temp = head;
		head = head->next;

		delete temp;
	}

	T top() {
		return head->data;
	}

	bool empty() {
		return head == NULL;
	}
};

int main() {

	Stack<char> s;
	s.push('A');
	s.push('B');
	s.push('C');
	s.push('D');

	while (!s.empty()) {
		cout << s.top() << " ";
		s.pop();
	}

	cout << endl;


	return 0;
}
















