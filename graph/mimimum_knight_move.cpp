#include<bits/stdc++.h>
using namespace std;

const int N = 10;
int vis[N][N];
int level[N][N];

vector < pair < int , int > > paths = {
 	{1, 2}, {2, 1}, {-1, 2}, {1, -2},
 	{-1, -2}, {-2, -1}, {-2, 1}, {2, -1}
};

int getX(string s) {return s[0] - 'a';}
int getY(string s) {return s[1] - '1';}

bool isValid(int x, int y) 
{return (x >= 0 and y >= 0 and x < 8 and y < 8);}

int bfs(string source, string dest) {
	int sx = getX(source);
	int sy = getY(source);
	int dx = getX(dest);
	int dy = getY(dest);

	queue < pair < int, int > > q;
	q.push({sx, sy});
	vis[sx][sy] = true;

	while (!q.empty()) {
		int parX = q.front().first;
		int parY = q.front().second;
		vis[parX][parY] = true;
		q.pop();
		for (auto crd: paths) {
			int childX = parX + crd.first;
			int childY = parY + crd.second;
			if (vis[childX][childY] or !isValid(childX, childY)) continue;
			vis[childX][childY] = true;
			q.push({childX, childY});
			level[childX][childY] = level[parX][parY] + 1;
		}
	}
	return level[dx][dy];
} 

void reset() {
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) 
			vis[i][j] = 0, level[i][j] = 0;
}

int main() {
	int t; cin >> t;
	while (t--) {
		string s1, s2;
		cin >> s1 >> s2;
		reset();
		cout << bfs(s1, s2) << '\n';
	}
	return 0;
}