#include<bits/stdc++.h>
using namespace std;

const int N = 1e3 + 7;
int par[N];
int lev[N];

void reset(int n) {for (int i = 0; i <= n; i++) par[i] = -1, lev[i] = 0;}
int Find(int n) {while (par[n] != -1) n = par[n];return n;}

void Union(int a, int b)
{
    int leaderA = Find(a);
    int leaderB = Find(b);
    if (leaderA != leaderB)
    {
        if (lev[leaderA] > lev[leaderB])
        {
            par[leaderB] = leaderA;
        }
        else if (lev[leaderB] > lev[leaderA])
        {
            par[leaderA] = leaderB;
        }
        else
        {
            par[leaderB] = leaderA;
            lev[leaderA]++;
        }
    }
}

int main() {
	int n, e; cin >> n >> e;
	reset(n);
	for (int i = 0; i < e; i++) {
		int x, y; cin >> x >> y;
		Union(x, y);
	} 
	for (int i = 1; i <= n; i++) cout << par[i] << ' ';
	return 0;
}