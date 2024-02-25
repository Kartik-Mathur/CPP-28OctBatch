#include <iostream>
#include <vector>
using namespace std;

class Minheap {
	vector<int> v;

	void heapify(int i) {
		int left = 2 * i;
		int right = 2 * i + 1;

		// Min index dhoondho i, left, right se
		int minIndex = i;
		if (left < v.size() and v[left] < v[minIndex]) {
			minIndex = left;
		}
		if (right < v.size() and v[right] < v[minIndex]) {
			minIndex = right;
		}

		// base case
		if (i != minIndex) {
			swap(v[i], v[minIndex]);
			heapify(minIndex);
		}
	}

public:
	Minheap() {
		v.push_back(-1);
	}

	void push(int d) {
		v.push_back(d);
		int c = v.size() - 1;
		int p = c / 2;

		while (p > 0 and v[p] > v[c]) {
			swap(v[p], v[c]);
			c = p;
			p /= 2;
		}
	}

	void pop() {
		swap(v[1], v[v.size() - 1]);
		v.pop_back();
		heapify(1);
	}

	int top() {
		return v[1];
	}

	bool empty() {
		return v.size() == 1;
	}

};

int main() {

	Minheap h;
	h.push(11);
	h.push(2);
	h.push(4);
	h.push(5);
	h.push(12);
	h.push(0);

	while (!h.empty()) {
		cout << h.top() << " ";
		h.pop();
	}
	cout << endl;


	return 0;
}
















