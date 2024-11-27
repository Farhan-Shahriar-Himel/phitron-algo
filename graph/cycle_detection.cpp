#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 7;
vector < int > g[N];
int vis[N];

bool dfs(int ver, int par = -1) {
	bool ok = false;
	vis[ver] = true;
	cout << ver << ' ';
	for (int child : g[ver]) {
		if (vis[child] and child != par) {
			//cout << child << ' ' << ver << ' ' << par << '\n';
			return true;
		}
		if (vis[child]) continue;
		ok |= dfs(child, ver);
	}
	return ok;
} 

int main() {
	int n, e; cin >> n >> e;
	for (int i = 1; i <= e; i++) {
		int x, y; cin >> x >> y;
		g[x].push_back(y);
		g[y].push_back(x);
	}

	bool ok = false;
	for (int i = 1; i <= n; i++) {
		if (vis[i]) continue;
		cout << "Components: ";
		ok = dfs(i);
		cout << (ok ? "YES" : "NO") << '\n';
	}
}