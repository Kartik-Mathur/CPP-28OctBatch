#include <iostream>
using namespace std;
class node {
public:
	string key;
	int value;
	node* next;
	node(string k, int v) {
		key = k;
		value = v;
		next = NULL;
	}
};

class hashmap {
	node** a;
	int ts;
	int cs;

	void rehash() {
		node** olda = a;
		int oldts = ts;

		ts *= 2;
		a = new node*[ts];
		cs = 0;
		for (int i = 0; i < ts; ++i)
		{
			a[i] = NULL;
		}

		for (int i = 0; i < oldts; ++i)
		{
			node* head = olda[i];
			while (head) {
				insert(head->key, head->value);
				node* temp = head;
				head = head->next;
				delete temp;
			}
		}

		delete[] olda;
	}

public:
	hashmap(int s = 7) {
		a = new node*[s];
		for (int i = 0; i < s; ++i)
		{
			a[i] = NULL;
		}
		ts = s;
		cs = 0;
	}

	int hashFunction(string key) {
		int ans = 0;
		int x = 1;
		for (int i = 0; i < key.size(); ++i)
		{
			ans += (x % ts) * (key[i] % ts);
			x *= 29 % ts;
			ans = ans % ts;
		}
		return ans % ts;
	}

	void insert(string key, int value) {
		node* n = new node(key, value);
		int hashIndex = hashFunction(key);

		n->next = a[hashIndex];
		a[hashIndex] = n;
		cs++;
		float loadFactor = (cs / (ts * 1.0));
		if ( loadFactor >  0.5) {
			rehash();// Double krdo current array ko
		}

	}

	void print() {
		for (int i = 0; i < ts; ++i)
		{
			cout << i << "--> ";
			node* head = a[i];
			while (head) {
				cout << "(" << head->key << ", " << head->value << ")";
				head = head->next;
			}
			cout << "NULL\n";
		}
	}

	node* search(string key) {
		int hashIndex = hashFunction(key);
		node* head = a[hashIndex];
		while (head) {
			if (head -> key == key) return head;

			head = head->next;
		}
		return NULL;
	}

	int& operator[](string key) {
		// Find update krna hai ya insert krna hai
		node* x = search(key);
		if (x == NULL) {
			// insert krna padega
			int garbageVal;
			insert(key, garbageVal);
			x = search(key);
			return x->value;

		}
		else {
			// update krna padega
			return x->value;
		}

	}

};

int main() {


	hashmap h;
	h.insert("Mango", 100);
	h.insert("apple", 120);
	h.insert("guava", 50);
	h.insert("kiwi", 40);


	h["pineapple"] = 50; // insert, new node create hogi hashmap mei
	cout << "Price: " << h["pineapple"] << endl; // 50 // print
	h["pineapple"] = 120; // update, pehle wali update ho rhi hai
	cout << "Price: " << h["pineapple"] << endl; // 120

	h.print();




	return 0;
}
















