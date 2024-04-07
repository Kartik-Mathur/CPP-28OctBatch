#include <iostream>
#include <list>
#include <queue>
#include <unordered_map>
#include <map>
using namespace std;

// #include "C://C++/library/graph.h" --> If kahi aur folder mei hai toh do this
// #include "graph.h"

template<typename T>
class Graph {
public:
	map<T, list<T> > adj;

	void addEdge(T u, T v, bool bidir = true) {
		adj[u].push_back(v);
		if (bidir) {
			adj[v].push_back(u);
		}
	}

	void print() {
		for (auto p : adj) {
			cout << p.first << "-->";
			for (auto v : p.second) {
				cout << v << ", ";
			}
			cout << endl;
		}
	}

	void dfsHelper(T src, unordered_map<T, bool> &visited) {
		cout << src << " ";
		visited[src] = true;
		for (auto ch : adj[src]) {
			if (!visited[ch]) {
				dfsHelper(ch, visited);
			}
		}
	}

	void dfs(T src) {
		unordered_map<T, bool > visited;
		int components = 1;
		dfsHelper(src, visited);

		for (auto p : adj) {
			if (!visited[p.first]) {
				dfsHelper(p.first, visited);
				components++;
			}
		}
		cout << "\nTotal components : " << components << endl;
	}
};

int main() {

	Graph<int> g;
	g.addEdge(0, 1);
	g.addEdge(2, 1);
	g.addEdge(2, 4);
	g.addEdge(2, 3);
	g.addEdge(0, 4);
	g.addEdge(3, 4);
	g.addEdge(3, 5);
	g.addEdge(13, 14);

	g.dfs(0);



	return 0;
}
















