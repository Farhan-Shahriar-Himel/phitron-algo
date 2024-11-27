#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 7;
vector < pair < int, int > > g[N];
vector < int > dist(N, INT_MAX), parent(N);
bool vis[N];

void dijkstra(int source) {
	priority_queue < 
		pair < int, int >, vector < pair < int, int > >,
		greater < pair < int, int > >
	> pq;
	dist[source] = 0;
	pq.push({dist[source], source});
	while (!pq.empty()) {
		int par = pq.top().second;
		pq.pop();
		vis[par] = true;
		for (auto child : g[par]) {
			int ver = child.first;
			int weight = child.second;
			if (vis[ver]) continue;
			if (dist[ver] > dist[par] + weight) {
				dist[ver] = dist[par] + weight;
				pq.push({dist[ver], ver});
			}
		}
	}
}

int main() {
	int n, e; cin >> n >> e;
	for (int i = 0; i < e; i++) {
		int x, y, w; cin >> x >> y >> w;
		g[x].push_back({y, w});
	}
	int src, dest; cin >> src >> dest;
	dijkstra(src);
	cout << dist[dest] << '\n';
}