#include <iostream>
#include <list>
#include <queue>
#include <unordered_map>
#include <map>
using namespace std;

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

	void bfs(T src) {
		queue<T> q;
		unordered_map<T, bool > visited;
		q.push(src);
		visited[src] = true;

		while (!q.empty()) {
			T f = q.front();
			q.pop();
			cout << f << " ";
			for (auto ch : adj[f]) {
				if (!visited[ch]) {
					q.push(ch);
					visited[ch] = true;
				}
			}
		}
		cout << endl;
	}

	// SSSP: Single Source Shortest Path Algorithm
	void SSSP(T src, T des) {
		queue<T> q;
		unordered_map<T, bool > visited;
		unordered_map<T, T > parent;
		unordered_map<T, int > distance;

		q.push(src);
		visited[src] = true;
		distance[src] = 0;
		parent[src] = src;

		while (!q.empty()) {
			T f = q.front();
			q.pop();
			for (auto ch : adj[f]) {
				if (!visited[ch]) {
					q.push(ch);
					distance[ch] = distance[f] + 1;
					visited[ch] = true;
					parent[ch] = f;
				}
			}
		}

		// Print the path from src to des
		while (des != parent[des]) {
			cout << des << "<--";
			des = parent[des];
		}
		cout << des << endl;

		// Printing all the distances from src node
		for (auto p : distance) {
			cout << "Distance of " << p.first << " from " << src << " : " << p.second << endl;
		}
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
	g.SSSP(0, 5);










	// g.addEdge(0, 1);
	// g.addEdge(0, 2);
	// g.addEdge(0, 3);
	// g.addEdge(2, 3);
	// g.addEdge(2, 1);
	// g.addEdge("Putin", "Modi", false);
	// g.addEdge("Putin", "Trump", false);
	// g.addEdge("Modi", "Trump", true);
	// g.addEdge("Modi", "Yogi", true);
	// g.addEdge("Yogi", "Prabhu", false);
	// g.addEdge("Prabhu", "Modi", false);
	// g.addEdge("Putin", "Pope", false);
	// g.print();

	return 0;
}
















