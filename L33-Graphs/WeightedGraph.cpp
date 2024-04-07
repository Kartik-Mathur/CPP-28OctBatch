#include <iostream>
#include <list>
#include <queue>
#include <unordered_map>
#include <map>
using namespace std;

template<typename T>
class Graph {
public:
	unordered_map<T, list<pair<T, int> > > adj;

	void addEdge(T u, T v, int dist, bool bidir = true) {
		adj[u].push_back({v, dist});
		if (bidir) adj[v].push_back({u, dist});
	}

	void print() {
		for (auto n : adj) {
			cout << n.first << "-->";
			for (auto p : n.second) {
				cout << "(" << p.first << ", " << p.second << ") ";
			}
			cout << endl;
		}
	}
};

int main() {

	Graph<string> g;

	g.addEdge("A", "B", 1);
	g.addEdge("C", "B", 2);
	g.addEdge("A", "C", 4);
	g.addEdge("D", "C", 3);
	g.addEdge("A", "D", 8);

	g.print();

	return 0;
}
















