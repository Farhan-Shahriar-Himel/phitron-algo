#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 7;
vector < pair < int, int > > g[N];
vector < int > dist(N, INT_MAX);
int vis[N];

void dijkstra(int root) {
	priority_queue < 
		pair < int, int > , vector < pair < int, int > >,
		greater < pair < int, int > >
	> pq;

	dist[root] = 0;
	pq.push({dist[root], root});

	while (!pq.empty()) {
		int par = pq.top().second;
		pq.pop();
		vis[par] = true;

		for (auto child: g[par]) {
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
	for (int i = 0 ; i < e; i++) {
		int x, y, w; cin >> x >> y >> w;
		g[x].push_back({y, w});
		g[y].push_back({x, w});
	}

	//dijkstra(1);

	// for (int i = 1; i <= n; i++) {
	// 	cout << "Distance of " << i << " is " << dist[i] << '\n';
	// }
	for (int i = 1; i <= n; i++) {
        cout << i << " = " << dist[i] << '\n';
    }
}