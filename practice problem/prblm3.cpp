#include<bits/stdc++.h>
using namespace std;

const int N = 1e3 + 7;
char g[N][N];
bool vis[N][N];
int n, m;

vector < pair < int , int > > paths = {
	{0, 1}, {0, -1}, {1, 0}, {-1, 0}
};

bool isValid(int x, int y) 
{return (x >= 0 and y >= 0 and x < n and y < m);}

void dfs(int x, int y) {
	vis[x][y] = true;
	//cout << x << ' ' << y << '\n';
	for (auto crd : paths) {
		int i = x + crd.first;
		int j = y + crd.second;
		//cout << i << ' ' << j << '\n';
		if (!isValid(i, j) or vis[i][j] or g[i][j] == 'x') continue;
		dfs(i, j);
	}
}

int main() {
	cin >> n >> m;
	int si, sj, ei, ej;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> g[i][j];
			if (g[i][j] == 's') si = i, sj = j;
			else if (g[i][j] == 'e') ei = i, ej = j;
		}
	}

	dfs(si, sj);
	cout << (vis[ei][ej] ? "YES\n": "NO\n"); 
	return 0;
}