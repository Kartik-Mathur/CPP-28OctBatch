#include <iostream>
using namespace std;

class DSU {
public:
	vector<int> parent;

	DSU(int n) {
		parent.resize(n + 1);
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
		parent[leader_v] = leader_u;
	}

	int find_set(int u) {
		if (parent[u] == u) return u;

		return find_set(parent[u]);
	}


};

int main() {


	return 0;
}
















