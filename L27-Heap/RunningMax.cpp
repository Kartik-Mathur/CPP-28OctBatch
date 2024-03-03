#include <iostream>
#include <queue>
#include <functional>
using namespace std;

void printHeap(priority_queue<int, vector<int>, greater<int> > q) {
	while (!q.empty()) {
		cout << q.top() << endl;
		q.pop();
	}
}

int main() {

	priority_queue<int, vector<int>, greater<int> > q; // Minheap

	int cnt_n = 0, number, k = 3;

	while (true) {
		cin >> number;
		if (number == -1) {
			// print the heap
			printHeap(q);

			continue;
		}

		if (cnt_n < k) {
			q.push(number);
			cnt_n++;
		}
		else {
			// Agar new number agar bada hota hai top wale element se
			// toh top ko pop kardo and new number ko insert kardo heap mei
			if (q.top() < number) {
				q.pop();
				q.push(number);
			}
		}
	}


	return 0;
}






