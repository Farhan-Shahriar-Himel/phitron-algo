#include<bits/stdc++.h>
using namespace std;

class Edge{
public:
	int parent, vertex, weight;
};

bool cmp(Edge a, Edge b) {
	return a.weight < b.weight;
}

const int N = 1e5 + 7;
vector < Edge > mst;
vector < int > par(N, -1), sze(N, 1);

int Find(int n) {while (par[n] != -1) n = par[n]; return n;}
void Union(int a,int b) {
	if (sze[a] < sze[b]) swap(a, b);
	par[b] = a;
	sze[a] += sze[b];
}

int main() {
	int n, e; cin >> n >> e;
	vector < Edge > edges;
	for (int i = 0; i < e; i++) {
		int x, y, w; cin >> x >> y >> w;
		edges.push_back({x, y, w});
	}
	sort(edges.begin(), edges.end(), cmp);

	for (auto edge: edges) {
		int a = Find(edge.parent);
		int b = Find(edge.vertex);
		if(a == b) continue;
		Union(a, b);
		mst.push_back(edge);
	}

	for (auto child: mst) 
		cout << child.parent << ' ' << child.vertex << ' ' << child.weight << '\n';

	return 0;
}