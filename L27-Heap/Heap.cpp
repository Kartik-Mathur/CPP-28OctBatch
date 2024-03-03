#include <iostream>
#include <queue>
#include <functional>
using namespace std;

class mycmp {
public:
	bool operator()(int a, int b) {
		return a < b;
	}
};

int main() {

	// priority_queue<int> q; // Max heap
	// priority_queue<int, vector<int>, greater<int> > q; // Minheap
	// priority_queue<int, vector<int>, less<int> > q; // Maxheap
	priority_queue<int, vector<int>, mycmp> q;

	q.push(10);
	q.push(2);
	q.push(4);
	q.push(3);
	q.push(1);

	while (!q.empty()) {
		cout << q.top() << endl;
		q.pop();
	}



	return 0;
}








