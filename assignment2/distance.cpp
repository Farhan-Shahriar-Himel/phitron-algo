#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
vector < int > g[N];
bool vis[N];
vector < int > level(N, 0);

void bfs(int ver) {
    vis[ver] = true;
    queue < int > q;
    q.push(ver);
    level[ver] = 0;

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

void reset() {
    for (int i = 0; i <= N; i++) {
        vis[i] = false;
        level[i] = 0;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int n, e; cin >> n >> e;
    for (int i = 0; i < e ; i++) {
        int x, y; cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    int q; cin >> q;
    while(q--) {
        reset();
        int f, d; cin >> f >> d;
        bfs(f);
        cout << (vis[d] ? level[d] : -1) << '\n';
    }
    return 0;
}