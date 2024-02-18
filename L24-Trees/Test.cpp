#include <iostream>
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

int countNodes(node* root) {
	// base case
	if (!root) return 0;
	// recurisve case
	return 1 + countNodes(root->left) + countNodes(root->right);
}

int height(node* root) {
	// base case
	if (!root) return 0;
	// recursive case

	return max(height(root->left), height(root->right)) + 1;
}

int diameter(node* root) {
	// base case
	if (!root) return 0;
	// recursive case
	// 1. Diameter via root node
	int op1 = height(root->left) + height(root->right);
	// 2. LST ka diameter
	int op2 = diameter(root->left);
	// 3. RST ka diameter
	int op3 = diameter(root->right);
	return max(op1, max(op2, op3));
}

class Pair {
public:
	int height;
	int diameter;
	Pair() {
		height = diameter = 0;
	}
};

Pair fastDiameter(node* root) {
	// base case
	if (!root) {
		Pair p;
		return p;
	}
	// recursive case
	// 1. LST se pair pucho
	Pair left = fastDiameter(root->left);
	// 2. RST se pair pucho
	Pair right = fastDiameter(root->right);

	Pair p;
	p.height = max(left.height, right.height) + 1;
	// diameter
	int op1 = left.height + right.height;
	int op2 = left.diameter;
	int op3 = right.diameter;
	p.diameter = max(op1, max(op2, op3));
	return p;
}

node* searchTree(node* root, int key) {
	// base case
	if (!root) return NULL;

	// recursive case
	if (root->data == key) return root;
	node* ans = searchTree(root->left, key);
	if (ans) return ans;
	return searchTree(root->right, key);
}

void mirror(node* root) {
	// base case
	if (!root) return;

	// recursive case
	swap(root->left, root->right);
	mirror(root->left);
	mirror(root->right);
}

// 8 10 1 -1 -1 6 4 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1
int main() {

	node* root = createTree();
	mirror(root);

	preOrder(root);
	cout << endl;
	inOrder(root);
	cout << endl;
	postOrder(root);

	cout << endl;

	cout << "Nodes Count: " << countNodes(root) << endl;
	cout << "Tree Height: " << height(root) << endl;
	cout << "Diameter: " << diameter(root) << endl;

	Pair p = fastDiameter(root);
	cout << "Fast Height:" << p.height << endl;
	cout << "Fast Dia:" << p.diameter << endl;

	node* ans = searchTree(root, 100);
	if (ans) {
		cout << "Found: " << ans->data << endl;
	}
	else {
		cout << "Not Found" << endl;
	}
	return 0;
}
















