#include <iostream>
#include <list>
using namespace std;

class Graph {
public:
	int n;
	list<int>* adj;
	Graph(int N) {
		n = N;
		adj = new list<int>[n];
	}

	void addEdge(int u, int v, bool bidir = true) {
		adj[u].push_back(v);
		if (bidir) {
			adj[v].push_back(u);
		}
	}

	void print() {
		for (int i = 0; i < n; ++i)
		{	cout << i << "--> ";
			for (auto d : adj[i]) {
				cout << d << ", ";
			}
			cout << endl;
		}
	}
};

int main() {

	Graph g(4);
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(0, 3);
	g.addEdge(2, 3);
	g.addEdge(2, 1);

	g.print();

	return 0;
}
















