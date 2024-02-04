#include <iostream>
using namespace std;

class node {
public:
	int data;
	node* next;// Jo class khud ka pointer store krti hai
	// usse kehte hai self referential class
	node(int d): data(d), next(NULL) {
		// data = d;
		// next = NULL;
	}
};

void printLL(node* head) {
	while (head) {
		cout << head->data << "-->";
		head = head->next;
	}
	cout << "NULL\n";
}


void insertAtEnd(node* &h, node* &t, int data) {
	if (h == NULL) {
		node* n = new node(data);
		h = t = n;
	}
	else {
		node* n = new node(data);
		t->next = n;
		t = n;
	}
}

int main() {

	node* head = NULL, *tail = NULL;

	insertAtEnd(head, tail, 1);
	insertAtEnd(head, tail, 2);
	insertAtEnd(head, tail, 3);
	insertAtEnd(head, tail, 4);
	insertAtEnd(head, tail, 5);

	printLL(head);




	return 0;
}
















