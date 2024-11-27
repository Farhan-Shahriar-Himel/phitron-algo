#include<bits/stdc++.h>
using namespace std;

const int N = 1e6+7;
vector < int > g[N];
bool vis[N];
int depth[N];
int height[N];

void dfs(int par) {
	vis[par] = true;
	for (int child: g[par]) {
		if (vis[child]) continue;
		depth[child] = depth[par] + 1;
		dfs(child);
		height[par] = max(height[par], height[child] + 1);
	}
}

int main() {
	int n, m; cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int u, v; cin >> u >> v;
		g[v].push_back(u);
		g[u].push_back(v);
	}
	dfs(1);
	for (int i = 1; i <= n; i++) {
		cout << i << " : " << height[i] << ' ' << depth[i] << '\n';
	}
}