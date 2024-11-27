#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
vector < pair < int, int > > g[N];
vector < int > d(N, INT_MAX);
bool vis[N];
int n, e;

void bellman_ford (int source) {
	d[source] = 0;
	for (int i = 0; i < n - 1; i++) {
		for (int par = 1; par <= n; par++) {
			for (auto child: g[par]) {
				int ver = child.first;
				int weight = child.second;
				if (d[par] == INT_MAX) continue;
				if (d[ver] > d[par] + weight) {
					d[ver] = d[par] + weight;
				}
			}
		}
	}
}

int main() {
	cin >> n >> e;
	for (int i = 0; i < e; i++) {
		int x, y, w; cin >> x >> y >> w;
		g[x].push_back({y, w});
	}
	bellman_ford(1);
	for (int i = 1; i <= n; i++) {
		cout << "d[" << i << "] = " << d[i] << '\n';
	}
	return 0;
}