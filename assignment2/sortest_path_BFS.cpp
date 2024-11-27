#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 7;
vector < int > g[N];
bool vis[N];
int par[N];
int dist[N];

void bfs(int root) {
	vis[root] = true;
	queue < int > q;
	q.push(root);
	par[root] = -1;
	while (!q.empty()) {
		int pr = q.front();
		q.pop();
		for (int child : g[pr]) {
			if (vis[child]) continue;
			vis[child] = true;
			q.push(child);
			dist[child] = dist[pr] + 1;
			par[child] = pr;
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

	bfs(1);

	int s, d; cin >> s >> d;
	int curr = d;
	vector < int > sp;
	while (curr != -1) {
		sp.push_back(curr);
		curr = par[curr];
	}
	reverse(sp.begin(), sp.end());
	cout << "Distance is : " << sp.size() << '\n';
	for (int it: sp) cout << it << ' ';
	return 0;
}