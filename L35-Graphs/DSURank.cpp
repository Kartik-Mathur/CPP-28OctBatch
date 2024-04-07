#include <iostream>
using namespace std;

class DSU {
public:
	vector<int> parent;
	vector<int> rank;

	DSU(int n) {
		parent.resize(n + 1);
		rank.resize(n + 1);
		for (int i = 1; i <= n; ++i)
		{
			rank[i] = 0;
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

		if (rank[leader_u] < rank[leader_v]) swap(leader_v, leader_u);
		if (rank[leader_v] == rank[leader_u]) rank[leader_u]++;
		parent[leader_v] = leader_u;
	}

	int find_set(int u) {
		if (parent[u] == u) return u;

		return parent[u] = find_set(parent[u]);
	}


};

int main() {


	return 0;
}
















