#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 7;
vector < int > g[N];
bool vis[N];
vector < int > ans[N];

void dfs(int ver, int ind) {
	vis[ver] = true;
	ans[ind].push_back(ver);
	for (int child: g[ver]) {
		if (vis[child]) continue;
		dfs(child, ind);
	}
}

int main() {
	int n, e; cin >> n >> e;
	for (int i = 0; i < e; i++) {
		int x, y; cin >> x >> y;
		g[x].push_back(y);
		g[y].push_back(x);
	}

	int cc = 0;
	for (int i = 1; i <= n; i++) {
		if (vis[i]) continue;
		cc++;
		dfs(i, cc);
	}

	cout << cc << endl;
	for (int i = 1; i <= cc; i++) {
		cout << "Components " << i << ": ";
		for (int ele: ans[i]) {
			cout << ele << ' ';
		}
		cout << '\n';
	}
	return 0;
}