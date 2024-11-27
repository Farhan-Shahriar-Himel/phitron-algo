#include<bits/stdc++.h>
using namespace std;

const int N = 1e6+7;
vector < int > g[N];
bool vis[N];
int level[N];

void bfs(int root) {
	vis[root] = true;
	queue < int > q;
	q.push(root);
	level[root] = 1;
	while(!q.empty()) {
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

int main() {
	int n, k; cin >> n >> k;
	for (int i = 0; i < k; i++) {
		int u, v; cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	bfs(1);
	for (int i = 1; i <= n; i++) {
		cout << "Level of " << i << " is " << level[i] << '\n';
	}
	return 0;
}