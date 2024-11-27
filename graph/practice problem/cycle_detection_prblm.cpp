#include<bits/stdc++.h>
using namespace std;

const int N = 1e6+7;
vector < int > g[N];
int vis[N];

bool dfs(int ver, int par = -1) {
	bool yes = false;
	vis[ver] = true;
	for (int child: g[ver]) {
		if (vis[child] and child != par) return true;
		if (vis[child]) continue;
		yes |= dfs(child, ver);
	}
	return yes;
}

int main() {
	int n, e; cin >> n >> e;
	for (int i = 0; i < e; i++) {
		int x, y; cin >> x >> y;
		g[x].push_back(y);
		g[y].push_back(x);
	}

	bool detected = false;
	for (int i = 1; i <= n; i++) {
		if (vis[i]) continue;
		detected |= dfs(i);
	}

	cout << (detected ? "YES\n" : "NO\n");
}