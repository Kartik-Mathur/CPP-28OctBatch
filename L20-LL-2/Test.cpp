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

int lenghtLL(node* head) {
	int cnt = 0;
	while (head != NULL) {
		cnt++;
		head = head->next;
	}
	return cnt;
}

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

void insertAtFront(node* &head, node* &tail, int data) {
	if (head == NULL) {
		node* n = new node(data);
		head = tail = n;
	}
	else {
		node* n = new node(data);
		n->next = head;
		head = n;
	}
}

void insertAtMiddle(node* &head, node* &tail, int data, int pos) {
	if (pos == 0) {
		insertAtFront(head, tail, data);
	}
	else if (pos >= lenghtLL(head)) {
		insertAtEnd(head, tail, data);
	}
	else {
		node* t = head;
		for (int i = 1; i <= pos - 1; ++i)
		{
			t = t->next;
		}

		node* n = new node(data);
		n->next = t->next;
		t->next = n;
	}
}

void deleteAtFront(node* &head, node* &tail) {
	if (!head) {
		return;
	}
	else if (!head->next) {
		delete head;
		head = tail = NULL;
	}
	else {
		node* t = head;
		head = head->next;
		delete t;
	}
}

void deleteAtEnd(node* &head, node* &tail) {
	if (!head) {
		return;
	}
	else if (!head->next) {
		delete head;
		head = tail = NULL;
	}
	else {
		node* t = head;
		while (t->next != tail) {
			t = t->next;
		}
		delete tail;
		tail = t;
		tail->next = NULL;
	}
}

void deleteAtMiddle(node* &head, node* &tail, int pos) {
	if (pos == 0) {
		deleteAtFront(head, tail);
		return;
	}
	if (pos >= lenghtLL(head) - 1) {
		deleteAtEnd(head, tail);
		return;
	}

	node* t = head;
	for (int i = 1; i <= pos - 1; ++i)
	{
		t = t->next;
	}

	node* n = t->next;
	t->next = n->next;
	delete n;
}

// node* searchLL(node*head, int key) {
// 	if (!head) return NULL;

// 	if (head->data == key) return head;
// 	return searchLL(head->next, key);
// }

// node* searchLL(node*head, int key) {
// 	if (!head || head->data == key) return head;

// 	return searchLL(head->next, key);
// }

node* searchLL(node*head, int key) {
	return (!head || head->data == key) ? head : searchLL(head->next, key);
}

void reverseLL(node*&head, node*&tail) {
	node* c = head;
	node* p = NULL;
	node* n;
	while (c) {
		n = c->next;
		c->next = p;
		p = c;
		c = n;
	}
	swap(head, tail);
}

void reverseLLRec(node* p, node* c) {
	// base case
	if (c == NULL) {
		return;
	}
	// recursive case
	node* n = c->next;
	c->next = p;
	reverseLLRec(c, n);
}

node* mid(node*head) {
	if (!head || head->next == NULL) return head;

	node* s = head;
	node* f = head->next;

	while (f and f->next) {
		f = f->next->next;
		s = s->next;
	}
	return s;
}

node* mergeLL(node*a, node*b) {
	if (a == NULL) return b;
	if (b == NULL) return a;

	// recursive case
	node* nH;
	if (a->data < b->data) {
		nH = a;
		nH->next = mergeLL(a->next, b);
	}
	else {
		nH = b;
		nH->next = mergeLL(a, b->next);
	}
	return nH;
}

node* mergeSort(node* head) {
	// base case
	if (!head || !head->next) return head;
	// recursive case
	// 1. Divide
	node* m = mid(head);
	node* a = head;
	node* b = m->next;
	m->next = NULL;
	// 2. Sort
	a = mergeSort(a);
	b = mergeSort(b);

	// 3. Merge
	node* nH = mergeLL(a, b);
	return nH;
}

int main() {

	node* head = NULL, *tail = NULL, *head1 = NULL, *tail1 = NULL;

	insertAtEnd(head, tail, 11);
	insertAtEnd(head, tail, 3);
	insertAtEnd(head, tail, -1);
	insertAtEnd(head, tail, 0);
	// insertAtEnd(head1, tail1, 2);
	// insertAtEnd(head1, tail1, 4);
	// insertAtEnd(head1, tail1, 7);
	// insertAtEnd(head1, tail1, 8);
	printLL(head);
	// printLL(head1);
	// head = mergeLL(head, head1);
	head = mergeSort(head);
	printLL(head);


	// insertAtEnd(head, tail, 1);
	// insertAtEnd(head, tail, 2);
	// insertAtEnd(head, tail, 3);
	// insertAtEnd(head, tail, 4);
	// insertAtEnd(head, tail, 5);
	// insertAtEnd(head, tail, 6);
	// insertAtEnd(head, tail, 7);
	// insertAtFront(head, tail, 6);
	// insertAtFront(head, tail, 7);
	// insertAtFront(head, tail, 8);

	// printLL(head);
	// insertAtMiddle(head, tail, 10, 5);
	// printLL(head);

	// reverseLL(head, tail);
	// reverseLLRec(NULL, head);
	// swap(head, tail);
	// printLL(head);

	// node* m = mid(head);
	// cout << "Middle: " << m->data << endl;
//
	// node* ans = searchLL(head, 4);

	// if (ans) {
	// 	cout << "Found: " << ans->data << endl;
	// }
	// else {
	// 	cout << "Not Found\n";
	// }




	return 0;
}
















