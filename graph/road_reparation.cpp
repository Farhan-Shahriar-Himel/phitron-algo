#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define sq(n) (n)*(n)

const int N = 2e5 + 7;
vector < pair < int, int > > g[N];
vector < pair < int , int > > mst;
bool vis[N];

ll prims(int root, int n) {
	ll ans = 0, cnt = 0;
	priority_queue < 
		pair < int , int >, vector < pair < int, int > >,
		greater < pair < int , int > >
	> pq;
	pq.push({0, 1});
	while(!pq.empty()) {
		auto parent = pq.top();
		pq.pop();

		int par = parent.second;
		int w = parent.first;
		if (vis[par]) continue;
		vis[par] = true;
		ans += (ll)w;
		cnt++;

		for (auto child: g[par]) {
			int ver = child.first;
			int wt = child.second;
			if (vis[ver]) continue;
			pq.push({wt, ver});
		}
	}

	return (n == cnt ? ans : -1); 
}

int32_t main() {
	ios_base::sync_with_stdio(NULL);
	cin.tie(nullptr); cout.tie(nullptr);

	int n, e; cin >> n >> e;
	for (int i = 0; i < e; i++) {
		int x, y, z; cin >> x >> y >> z;
		g[x].push_back({y, z});
		g[y].push_back({x, z});
	}
	ll ans = prims(1, n);
	if (ans == -1) cout << "IMPOSSIBLE" << '\n';
	else cout << ans << '\n';
	return 0;
}