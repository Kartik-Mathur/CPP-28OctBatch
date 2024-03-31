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
		cout << "Min Moves: " << distance[des] << endl;
		while (des != parent[des]) {
			cout << des << "<--";
			des = parent[des];
		}
		cout << des << endl;

		// Printing all the distances from src node
		// for (auto p : distance) {
		// 	cout << "Distance of " << p.first << " from " << src << " : " << p.second << endl;
		// }
	}
};

int main() {

	Graph<int> g;
	int board[50] = {0};
	board[2] = 13;
	board[5] = 2;
	board[9] = 18;
	board[18] = 11;
	board[17] = -13;
	board[20] = -14;
	board[24] = -8;
	board[25] = -10;
	board[32] = -2;
	board[34] = -22;

	for (int u = 0; u <= 36; ++u)
	{
		for (int dice = 1; dice <= 6; ++dice)
		{
			int v = u + dice;
			v += board[v];
			g.addEdge(u, v, false);
		}
	}


	g.SSSP(0, 36);












	return 0;
}
















