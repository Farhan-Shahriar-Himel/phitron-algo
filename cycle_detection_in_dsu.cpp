#include<bits/stdc++.h>
using namespace std;

const int N = 1e3 + 7;
int par[N];
int sze[N];

void reset(int n) {for (int i = 0; i <= n; i++) par[i] = -1, sze[i] = 1;}
int Find(int n) {while (par[n] != -1) n = par[n]; return n;}

void Union(int a, int b) {
	if (sze[a] < sze[b]) swap(a, b);
	par[b] = a;
	sze[a] += sze[b];
}

int main() {
	int n, e; cin >> n >> e;
	reset(n);
	for (int i = 0; i < e; i++) {
		int x, y; cin >> x >> y;
		x = Find(x);
		y = Find(y);

		if (x == y) cout << "Cycle Detected" << '\n';
		else Union(x, y);
	}
	for (int i = 1; i <= n; i++) cout << par[i] << ' ';
}