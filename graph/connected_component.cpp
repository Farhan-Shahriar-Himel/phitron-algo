#include<bits/stdc++.h>
using namespace std;

const int N = 1e6+7;
vector < int > g[N];
int vis[N];

void dfs(int par) {
	vis[par] = true;
	cout << par << ' ';
	for (int child: g[par]) {
		if (vis[child]) continue;
		dfs(child);
	}
}

int main() {
	int n, k; cin >> n >> k;
	for (int i = 0; i < k; i++) {
		int u, v; cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	int cc = 1;
	for (int i = 1; i <= n; i++) {
		if (vis[i]) continue;
		cout << "Components " << cc << ": ";
		dfs(i); cc++;
		cout << '\n';
	}
	//cout << cc << '\n';
}