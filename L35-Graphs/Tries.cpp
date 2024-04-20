#include <iostream>
#include <unordered_map>
using namespace std;

class node {
public:
	char ch;
	unordered_map <char, node*> h;
	bool isEnd;
	node(char c) {
		ch = c;
		isEnd = false;
	}
};

class Trie {
public:
	node* root;
	Trie() {
		root = new node('\0');
	}

	void insertWord(string &s) {
		node* t = root;

		for (auto ch : s) {
			if (t->h.count(ch) == 0) {
				t->h[ch] = new node(ch);
			}

			t = t->h[ch];
		}
		t->isEnd = true;
	}

	bool isWordPresent(string &s) {
		node* t = root;

		for (auto ch : s) {
			if (t->h.count(ch) == 0) {
				return false;
			}

			t = t->h[ch];
		}
		return t->isEnd;
	}
};

int main() {

	string s[] = {
		"Hello", "Her", "He", "Code", "Coder"
	};

	int n = 5;
	Trie t;
	for (int i = 0; i < n; ++i)
	{
		t.insertWord(s[i]);
	}

	while (1) {
		string x; cin >> x;

		if (t.isWordPresent(x)) cout << "Present\n";
		else cout << "Present Nahi hai\n";
	}

	return 0;
}
















