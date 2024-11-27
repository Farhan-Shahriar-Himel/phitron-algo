#include<bits/stdc++.h>
using namespace std;

class Edge{
public:
	int parent, vertex, weight;
};

class cmp {
public:
	operator()(Edge a, Edge b) {
		return a.weight > b.weight;
	}
};

const int N = 1e5 + 7;
vector < pair < int, int > > g[N];
vector < Edge > mst;
bool vis[N];

void prims(int source) {
	priority_queue < Edge, vector < Edge >, cmp > pq;

	pq.push({source, source, 0});
	while (!pq.empty()) {
		Edge parent = pq.top();
		pq.pop();

		int n_par = parent.vertex;
		if (vis[n_par]) continue;
		vis[n_par] = true;
		mst.push_back(parent);

		for (auto child: g[n_par]) {
			int ver = child.first;
			int wt = child.second;
			if (vis[ver]) continue;
			pq.push({n_par, ver, wt});
		}
	}
	mst.erase(mst.begin());
}

int main() {
	int n, e; cin >> n >> e;
	for (int i = 0; i < e; i++) {
		int x, y, w; cin >> x >> y >> w;
		g[x].push_back({y, w});
		g[y].push_back({x, w});
	}
	prims(1);

	for (Edge it: mst) 
		cout << it.parent << ' ' << it.vertex << ' ' << it.weight << '\n';

	return 0;
}