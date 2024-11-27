#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 1e6 + 7;
vector < int > g[N];
bool vis[N];
vector < int > level(N, 0);

void dfs(int ver) {
	vis[ver] = true;
	for (int child: g[ver]) {
		if (vis[child]) continue;
		dfs(child);
	}
}

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, e; cin >> n >> e;
	for (int i = 0; i < e; i++) {
		int x, y; cin >> x >> y;
		g[x].push_back(y);
	}
	int k; cin >> k;
	dfs(k);
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		if (vis[i] and i != k) ans++;
	}
	cout << ans << '\n';
}