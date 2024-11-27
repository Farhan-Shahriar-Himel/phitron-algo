#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define sq(n) (n)*(n)

const int N = 1e6 + 7;
vector < int > g[N];
int vis[N];

int bfs(int ver) {
	vis[ver] = true;
	queue < int > q;
	q.push(ver);
	int cnt = 1;
	while (!q.empty()) {
		int par = q.front();
		q.pop();
		for (int child: g[par]) {
			if (vis[child]) continue;
			vis[child] = true;
			q.push(child);
			cnt++;
		}
	}
	return cnt;
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, e; cin >> n >> e;
	for (int i = 0; i < e; i++) {
		int x, y; cin >> x >> y;
		g[x].push_back(y);
		g[y].push_back(x);
	}

	vector < ll > ans;
	for (int i = 0; i <= 1000; i++) {
		ll len = bfs(i);
		if (len > 1) ans.push_back(len);
	}

	sort(ans.begin(), ans.end());

	for (int it: ans) cout << it << " ";
	
	return 0;
}
