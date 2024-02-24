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

node* createTree() {
	int data;
	cin >> data;
	if (data == -1) return NULL;

	// Pehle root node banai
	node* root = new node(data);

	// Left Subtree create karo
	root->left = createTree();
	// Right Subtree create karo
	root->right = createTree();
	return root;
}

void preOrder(node*root) {
	if (!root) return;

	cout << root->data << ", ";
	preOrder(root->left);
	preOrder(root->right);
}

void inOrder(node*root) {
	if (!root) return;

	inOrder(root->left);
	cout << root->data << ", ";
	inOrder(root->right);
}

void postOrder(node*root) {
	if (!root) return;

	postOrder(root->left);
	postOrder(root->right);
	cout << root->data << " ";
}

int height(node* root) {
	// base case
	if (!root) return 0;
	// recursive case

	return max(height(root->left), height(root->right)) + 1;
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

node*  levelOrderInput() {
	node* root = NULL;
	cout << "Enter Root Data: ";
	int data;
	cin >> data;

	if (data == -1) return NULL;
	root = new node(data);

	queue<node*> q;
	q.push(root);

	while (!q.empty()) {
		node* n = q.front();
		q.pop();
		cout << "Enter children of " << n->data << " : ";
		int l, r;
		cin >> l >> r;
		if (l != -1) {
			n->left = new node(l);
			q.push(n->left);
		}

		if (r != -1) {
			n->right = new node(r);
			q.push(n->right);
		}
	}

	return root;
}

int pre[] = {8, 10, 1, 6, 4, 7, 3, 14, 13};
int in[] = {1, 10, 4, 6, 7, 8, 3, 13, 14};
int i = 0;

node* buildTree(int s, int e) {
	// base case
	if (s > e) return NULL;

	// recursive case
	int d = pre[i++];
	node* root = new node(d);
	int k;
	for (int j = s; j <= e; ++j)
	{
		if (in[j] == d) {
			k = j;
			break;
		}
	}

	root->left = buildTree(s, k - 1);
	root->right = buildTree(k + 1, e);
	return root;
}

// 8 10 1 -1 -1 6 4 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1
int main() {

	// node* root = createTree();
	node* root = buildTree(0, 8);
	// node* root = levelOrderInput();

	preOrder(root);
	cout << endl;
	inOrder(root);
	cout << endl;
	postOrder(root);

	cout << endl;

	levelOrderPrint(root);

	return 0;
}
















