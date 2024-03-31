#include <iostream>
#include <list>
#include <set>
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


	void dijkstras(T src, T des) {
		unordered_map<T, int> distance;
		unordered_map<T, T> parent;

		// Saari nodes ka initial distance inifinity kardo
		for (auto n : adj[src]) {
			distance[n.first] = INT_MAX;
		}

		// Src ka khud se distance toh zero hoga
		distance[src] = 0;
		parent[src] = src; // src ka parent bhi src khud hi hoga

		// set ke andar pair.first is the distance kyunki ussi ke basis par
		// sort krna hai hume
		set<pair<int, T>>s;
		s.insert({distance[src], src});

		while (!s.empty()) {
			auto p = *s.begin();
			s.erase(s.begin());

			T par = p.second;
			int pard = p.first;

			for (auto n : adj[par]) {
				T ch = n.first;
				int ed = n.second;
				if (distance[ch] > distance[par] + ed) {
					auto x = s.find({distance[ch], ch});
					if (x != s.end()) {
						s.erase(x);
					}

					distance[ch] = pard + ed;
					parent[ch] = par;
					s.insert({distance[ch], ch});
				}
			}
		}

		for (auto n : distance) {
			cout << "Distance of " << n.first
			     << " from " << src << " : " << n.second << endl;
		}

		while (des != parent[des]) {
			cout << des << "<--";
			des = parent[des];
		}
		cout << des << endl;

	}
};

int main() {

	Graph<string> g;

	g.addEdge("A", "B", 1);
	g.addEdge("C", "B", 2);
	g.addEdge("A", "C", 4);
	g.addEdge("D", "C", 3);
	g.addEdge("A", "D", 8);

	// g.print();
	g.dijkstras("A", "D");

	return 0;
}
















