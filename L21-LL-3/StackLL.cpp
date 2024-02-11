#include <iostream>
using namespace std;

class node {
public:
	int data;
	node* next;
	node(int d) {
		data  = d;
		next = NULL;
	}
};

class Stack {
	node* head;
public:
	Stack() {
		head = NULL;
	}

	void push(int d) {
		if (head == NULL) {
			head = new node(d);
		}
		else {
			node* n = new node(d);
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

		node* temp = head;
		head = head->next;

		delete temp;
	}

	int top() {
		return head->data;
	}

	bool empty() {
		return head == NULL;
	}
};

int main() {

	Stack s;
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);

	while (!s.empty()) {
		cout << s.top() << " ";
		s.pop();
	}

	cout << endl;


	return 0;
}
















