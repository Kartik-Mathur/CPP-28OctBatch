#include <iostream>
using namespace std;

class Queue {
	int *a;
	int n;
	int cs;
	int f, e;
public:
	Queue(int s = 5) {
		a = new int[s];
		n = s;
		cs = 0;
		f = 0;
		e = n - 1;
	}

	void push(int d) {
		if (cs == n) {
			cout << "Queue Overflow\n";
			return;
		}

		e = (e + 1) % n;
		a[e] = d;
		cs++;
	}

	void pop() {
		if (cs <= 0) {
			cout << "Queue Underflow\n";
			return;
		}

		f = (f + 1) % n;
		cs--;
	}

	bool empty() {
		return cs == 0;
	}

	int front() {
		return a[f];
	}
};



int main() {

	Queue q;

	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	q.push(5);

	while (!q.empty()) {
		cout << q.front() << " ";
		q.pop();
	}
	cout << endl;
	q.pop();


	return 0;
}
















