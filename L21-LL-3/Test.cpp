#include <iostream>
using namespace std;

class node {
public:
	int data;
	node* next;

	node(int d): data(d), next(NULL) {}
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

node* searchLL(node*head, int key) {
	return (!head || head->data == key) ? head : searchLL(head->next, key);
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

void bubbleSort(node* &head) {
	node* c, *p, *n;
	int len = lenghtLL(head);
	for (int i = 0; i < len - 1; ++i)
	{
		c = head;
		p = NULL;

		while (c and c->next) {
			n = c->next;

			if (c->data > n->data) {
				// swapping hogi
				if (p == NULL) { // head change hoga
					c->next = n->next;
					n->next = c;
					p = head = n;
				}
				else { // head change nahi hoga
					c->next = n->next;
					n->next = c;
					p->next = n;
					p = n;
				}
			}
			else {
				// swapping nahi hogi
				p = c;
				c = n;
			}
		}
	}
}

void breakCycle(node* head, node* f) {
	node* s = head;
	node* fp = head;
	while (fp->next != f) {
		fp = fp->next;
	}

	while (f != s) {
		fp = f;
		f = f->next;
		s = s->next;
	}

	fp->next = NULL;
}

bool isCyclic(node* head) {
	node* s, *f;
	s = f = head;
	while (f and f->next) {
		f = f->next->next;
		s = s->next;

		if (f == s) {
			cout << "f and s met at: " << f->data << endl;
			breakCycle(head, f);
			return true;
		}
	}

	return false;
}

int main() {

	node* head = NULL, *tail = NULL, *head1 = NULL, *tail1 = NULL;

	insertAtEnd(head, tail, 1);
	insertAtEnd(head, tail, 2);
	insertAtEnd(head, tail, 3);
	insertAtEnd(head, tail, 4);
	insertAtEnd(head, tail, 5);
	insertAtEnd(head, tail, 6);
	insertAtEnd(head, tail, 7);
	insertAtEnd(head, tail, 8);

	printLL(head);

	tail->next = head->next;

	if (isCyclic(head)) {

		cout << "Cycle Hai\n";
		printLL(head);
	}
	else {
		cout << "Cycle Nahi hai\n";
	}


	return 0;
}
















