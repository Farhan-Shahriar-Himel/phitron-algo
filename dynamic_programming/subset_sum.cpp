#include<bits/stdc++.h>
using namespace std;

const int N = 1e3 + 7;
int a[N];
vector < vector < int > > dp(N, vector < int > (N, -1));
int n, k;

int subset_sum(int n, int w) {

	if (!n and !w) return true;
	if (!n) return false;
	if (dp[n][w] != -1) return dp[n][w]; 

	bool op1 = false, op2 = false;
	if(a[n - 1] <= w) op1 = subset_sum(n - 1, w - a[n - 1]);
	op2 = subset_sum(n - 1, w);
	return dp[n][w] = op1 || op2;
}

int main() {
	//memset(dp, -1, sizeof(dp));
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	cin >> k;
	bool possible = subset_sum(n, k);
	cout << (possible ? "YES": "NO") << "\n";
	return 0;
}