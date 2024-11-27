#include<bits/stdc++.h>
using namespace std;

const int N = 1e3+7;
int g[N][N];

int main() {
	int n, m; cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v; cin >> u >> v;
		g[u][v] = 1;
		g[v][u] = 1;
	}
	for (int i = 1; i < m; i++) {
		for (int j = 0; j < m; j++) {
			cout << g[i][j] << ' ';
		} 
		cout << '\n';
	}
}