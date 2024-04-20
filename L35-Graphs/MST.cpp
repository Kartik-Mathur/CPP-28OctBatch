#include <iostream>
#include <vector>
using namespace std;

class DSU {
public:
	vector<int> parent;
	vector<int> size;

	DSU(int n) {
		parent.resize(n + 1);
		size.resize(n + 1);
		for (int i = 1; i <= n; ++i)
		{
			size[i] = 1;
		}

		create_set();
	}

	void create_set() {
		for (int i = 1; i <= parent.size(); ++i)
		{
			parent[i] = i;
		}
	}

	void union_set(int u, int v) {
		int leader_u = find_set(u);
		int leader_v = find_set(v);

		if (leader_u == leader_v) return;

		if (size[leader_u] < size[leader_v]) swap(leader_v, leader_u);
		parent[leader_v] = leader_u;
		size[leader_u] += size[leader_v];
	}

	int find_set(int u) {
		if (parent[u] == u) return u;

		return parent[u] = find_set(parent[u]);
	}


};


class Edge {
public:
	int u, v, w;
	Edge(int u, int v, int w) {
		this->u = u;
		this->v = v;
		this->w = w;
	}
};

bool compare(Edge &a, Edge& b) {
	return a.w < b.w;
}

// input: 6 1 3 2 1 2 1 2 4 2 5 4 1 2 5 4 3 5 3
// output: 6

int main() {

	vector<Edge> a;
	int edges; cin >> edges;
	int nodes = 0;
	for (int i = 0; i < edges; ++i)
	{
		int u, v, w;
		cin >> u >> v >> w;
		nodes = max(u, v);
		a.push_back({u, v, w});
	}

	sort(a.begin(), a.end(), compare);
	// for (int i = 0; i < a.size(); ++i)
	// {
	// 	cout << "u " << a[i].u << ", v: " << a[i].v << ", w: " << a[i].w << endl;
	// }

	DSU d(nodes);
	int ans = 0;
	for (auto e : a) {
		int u = e.u, v = e.v, w = e.w;
		int leader_u = d.find_set(u);
		int leader_v = d.find_set(v);
		if (leader_u !=  leader_v) {
			d.union_set(leader_v, leader_u);
			ans += w;
		}
	}

	cout << ans << endl;


	return 0;
}
















