#ifndef Graph_STL
#define Graph_STL
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

#endif