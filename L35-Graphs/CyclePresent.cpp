#include <iostream>
#include <vector>
#include <map>
#include <list>
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

	bool isCyclic(list<pair<int, int > > &l) {
		for (auto p : l) {
			int u = p.first, v = p.second;

			int leader_u = find_set(u);
			int leader_v = find_set(v);

			if (leader_u == leader_v) return true;
			union_set(leader_u, leader_v);
		}
		return false;
	}

};

int main() {
	DSU d(4);
	list<pair<int, int> > l;
	int edges;
	cin >> edges;

	for (int i = 0; i < edges; ++i)
	{
		int u, v; cin >> u >> v;
		l.push_back({u, v});
	}

	if (d.isCyclic(l)) {
		cout << "Cycle hai\n";
	}
	else {
		cout << "Cycle Nahi hai\n";
	}




	return 0;
}
















