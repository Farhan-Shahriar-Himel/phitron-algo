#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
vector < int > par(N, -1), sze(N, 1);

class dsu {
public:
	int n;
	void in() {cin >> n;}
	int Find() {
		int cn = n;
		while (par[cn] != -1) cn = par[cn];
		return cn;
	}
	void Union(dsu &ob) {
		int a = Find();
		int b = ob.Find();
		if (a == b) return;
		if (sze[a] < sze[b]) swap(a, b);
		par[b] = par[a];
		sze[a] += sze[b];
	}
};

int main() {
	int n, e; cin >> n >> e;
	for (int i = 0; i < e; i++) {
		dsu x, y; 
		x.in(); y.in();
		x.Union(y);
	}
	for (int i = 1; i <= 5; i++) cout << par[i] << " ";
}