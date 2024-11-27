#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 7;
vector < int > g[N];
bool vis[N];
int level[N];

void bfs(int ver) {
	vis[ver] = true;
	queue < int > q;
	q.push(ver);
	while (!q.empty()) {
		int par = q.front();
		q.pop();
		for (int child: g[par]) {
			if(vis[child]) continue;
			vis[child] = true;
			q.push(child);
			level[child] = level[par] + 1;
		}
	}
}

int main() {
	int n, e; cin >> n >> e;
	for (int i = 0; i < e; i++) {
		int x, y; cin >> x >> y;
		g[x].push_back(y);
		g[y].push_back(x);	
	} 
	int k; cin >> k;
	bfs(1);
	cout << "Level of " << k << " = " << level[k];
	return 0;
}