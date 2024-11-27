#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 7;
vector < int > g[N];
bool vis[N];

void dfs(int par) {
	vis[par] = true;
	for (int child : g[par]) {
		if (vis[child]) continue;
		dfs(child);
	}	
}

int main() {
	int n, m; cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u , v; cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	dfs(1);
	for (int i = 1; i <= n; i++) cout << vis[i] << '\n';
	return 0;
}