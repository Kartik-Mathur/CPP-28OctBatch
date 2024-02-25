#include <iostream>
#include <queue>
using namespace std;


class node {
public:
	int data;
	node* left, *right;
	node(int d) {
		data = d;
		left = right = NULL;
	}
};

node* insertInBST(node* root, int d) {
	// base case
	if (!root) {
		root = new node(d);
		return root;
	}

	// recursive case
	if (root->data >= d) {
		root -> left = insertInBST(root->left, d);
	}
	else {
		root -> right = insertInBST(root->right, d);
	}
	return root;
}

void printRangeBST(node* root, int k1, int k2) {
	if (!root) return;

	if (root->data >= k1 and root->data <= k2) {
		cout << root->data << " ";
	}

	if (root->data < k1) {
		printRangeBST(root->right, k1, k2);
	}
	else if (root->data > k2) {
		printRangeBST(root->left, k1, k2);
	}
	else {
		printRangeBST(root->left, k1, k2);
		printRangeBST(root->right, k1, k2);
	}
}

node* createTree() {
	int data;
	cin >> data;
	if (data == -1) return NULL;

	node* root = NULL;
	while (data != -1) {
		root = insertInBST(root, data);

		cin >> data;
	}

	return root;
}

void preOrder(node*root) {
	if (!root) return;

	cout << root->data << " ";
	preOrder(root->left);
	preOrder(root->right);
}

void inOrder(node*root) {
	if (!root) return;

	inOrder(root->left);
	cout << root->data << " ";
	inOrder(root->right);
}

void postOrder(node*root) {
	if (!root) return;

	postOrder(root->left);
	postOrder(root->right);
	cout << root->data << " ";
}

void levelOrderPrint(node* root) {
	queue<node* >q;
	q.push(root);
	q.push(NULL);
	while (!q.empty()) {
		node* n = q.front();
		q.pop();

		if (n == NULL) {
			cout << endl;
			if (!q.empty()) {
				q.push(NULL);
			}
		}
		else {
			cout << n->data << " ";
			if (n->left) q.push(n->left);
			if (n->right) q.push(n->right);
		}
	}
}

int height(node* root) {
	if (!root) return 0;

	return (max(height(root->left), height(root->right))) + 1;
}

bool isBalanced(node* root) {
	// base case
	if (!root) return true;

	// recursive case
	int left = height(root->left);
	int right = height(root->right);

	if (abs(left - right) <= 1 and
	        isBalanced(root->left) and isBalanced(root->right)) {
		return true;
	}
	else {
		return false;
	}
}

class Pair {
public:
	bool balanced;
	int height;
};
Pair fastBalanced(node* root) {
	// base case
	if (!root) {
		return {true, 0};
	}
	// recursive case
	Pair p;
	Pair left = fastBalanced(root->left);
	Pair right = fastBalanced(root->right);

	p.height = max(left.height, right.height) + 1;
	if (abs(left.height - right.height) <= 1 and left.balanced and right.balanced) {
		p.balanced = true;
	}
	else {
		p.balanced = false;
	}
	return p;
}

class LinkedList {
public:
	node* head, *tail;
};

LinkedList BSTtoLL(node* root) {
	// base case
	if (!root) {
		return {NULL, NULL};
	}
	// recursive case
	LinkedList l;

	if (root->left and root->right) {
		LinkedList left =
		    BSTtoLL(root->left);
		LinkedList right =
		    BSTtoLL(root->right);

		left.tail->right = root;
		root->right = right.head;

		l.head = left.head;
		l.tail = right.tail;
		return l;
	}
	else if (root->left and !root->right) {
		LinkedList left = BSTtoLL(root->left);
		left.tail->right = root;
		l.head = left.head;
		l.tail = root;
		return l;
	}
	else if (!root->left and root->right) {
		LinkedList right = BSTtoLL(root->right);
		root->right = right.head;
		l.head = root;
		l.tail = right.tail;
		return l;
	}
	else {
		l.head = l.tail = root;
		return l;
	}
}

void printLL(node* head) {
	while (head) {
		cout << head->data << "-->";
		head = head->right;
	}
	cout << "NULL\n";
}

int main() {

	node* root = createTree();

	preOrder(root);
	cout << endl;
	inOrder(root);
	cout << endl;
	postOrder(root);
	cout << endl;

	levelOrderPrint(root);
	// cout << endl;
	printRangeBST(root, 3, 10);
	cout << endl;
	if (isBalanced(root)) {
		cout << "Balanced Hai\n";
	}
	else {
		cout << "Balanced Nahi Hai\n";
	}

	Pair ans = fastBalanced(root);
	cout << ans.height << endl;

	if (ans.balanced) {
		cout << "Balanced Hai\n";
	}
	else {
		cout << "Balanced Nahi Hai\n";
	}


	LinkedList l = BSTtoLL(root);

	printLL(l.head);
	return 0;
}
















