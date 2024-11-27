#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 1e6 + 7;
vector < int > g[N];
bool vis[N];
vector < int > level(N, 0);

void bfs(int ver) {
	vis[ver] = true;
	queue < int > q;
	q.push(ver);

	while (!q.empty()) {
		int par = q.front();
		q.pop();
		for (int child: g[par]) {
			if (vis[child]) continue;
			vis[child] = true;
			q.push(child);
			level[child] = level[par] + 1;
		}
	}
}

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, e; cin >> n >> e;
	for (int i = 0; i < e; i++) {
		int x, y; cin >> x >> y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	int k; cin >> k;
	bfs(k);
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		if (vis[i] and level[i] == 1) ans++;
	}
	cout << ans << '\n';
}