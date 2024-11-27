#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define sq(n) (n)*(n)

class Edge {
public:
    ll parent, vertex, weight;
};

const ll N = 1e3 + 7;
const ll inf = 1e18 + 7;
vector < ll > dist(N, inf);

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    vector < Edge > edges;
    int n, e; cin >> n >> e;
    for (int i = 0; i < e; i++) {
        int x, y, z; cin >> x >> y >> z;
        edges.push_back({x, y, z});
    }    
    int src; cin >> src;   
    dist[src] = 0;

    for (int i = 0; i < n - 1; i++) {
        for (auto edge: edges) {
            ll par = edge.parent;
            ll ver = edge.vertex;
            ll wt = edge.weight;
            if (dist[par] == inf) continue;
            if (dist[ver] > dist[par] + wt) 
                dist[ver] = dist[par] + wt;
        }
    }

    for (auto edge: edges) {
        ll par = edge.parent;
        ll ver = edge.vertex;
        ll wt = edge.weight;
        if (dist[par] == inf) continue;
        if (dist[ver] > dist[par] + wt) {
            int q; cin >> q;
            while(q--) {int x; cin >> x;}
            cout << "Negative Cycle Detected\n";
            return 0;
        }
    }
    int q; cin >> q;
    while (q--) {
        int x; cin >> x;
        if (dist[x] != inf) cout << dist[x] << '\n';
        else cout << "Not Possible\n";
    }
    return 0;
}