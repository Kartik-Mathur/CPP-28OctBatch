#include <iostream>
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

int main() {


	return 0;
}
















