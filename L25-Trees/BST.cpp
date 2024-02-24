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

int main() {

	node* root = createTree();

	preOrder(root);
	cout << endl;
	inOrder(root);
	cout << endl;
	postOrder(root);
	cout << endl;

	levelOrderPrint(root);


	return 0;
}
















