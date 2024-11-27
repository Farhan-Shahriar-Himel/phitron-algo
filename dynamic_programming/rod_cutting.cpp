#include<bits/stdc++.h>
using namespace std;

const int N = 1e3 + 7;
vector < vector < int > > dp(N, vector < int > (N, -1)); 
vector < int > DP(N, -1);
int val[N], wt[N];

int ways(int n, int w) {
	if (n == 0 or w == 0) return 0;
	if (dp[n][w] != -1) return dp[n][w];

	if (wt[n - 1] <= w) {
		int op1 = val[n - 1] + ways(n, w - wt[n - 1]);
		int op2 = ways(n - 1, w);
		return dp[n][w] = max(op1 , op2);
	}
	return dp[n][w] = ways(n - 1, w);
}

int Ways(int n) {
	if (!n) return 0;
	if (DP[n] != -1) return DP[n];
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (n - i >= 0)
			ans = max(ans, Ways(n - i) + val[i - 1]);
	}
	return DP[n] = ans;
}

int main() {

	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> val[i];
		wt[i] = i + 1;
	}

	cout << ways(n, n) << "\n";
	// this Way is much better
	cout << Ways(n) << "\n";
	return 0;
}