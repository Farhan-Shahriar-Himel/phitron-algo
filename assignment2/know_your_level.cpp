#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 7;
vector < int > g[N];
int vis[N];
vector < int > level(N, 0);

void bfs(int root) {
    vis[root] = 1;
    queue < int > q;
    q.push(root);
    level[root] = 0;

    while(!q.empty()) {
        int par = q.front();
        q.pop();
        for (int child: g[par]) {
            if (vis[child]) continue;
            vis[child] = 1;
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
    bfs(0);
    bool ok = false;
    for (int i = 0; i <= 100000; i++) {
        if (vis[i] and level[i] == k) {
            cout << i << ' ';
            ok = true;
        }
    }
    if (!ok) cout << -1 << '\n';
    return 0;
}