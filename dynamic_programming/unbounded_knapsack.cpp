#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 1e3 + 7;
vector < int > val(N), wt(N);
vector < vector < int > > dp(N, vector < int > (N, -1));

int unbounded_knapsack(int n, int w) {
	if (!n or !w) return 0;
	if (dp[n][w] != -1) return dp[n][w];

	if (w - wt[n - 1] >= 0) {
		int op1 = val[n - 1] + unbounded_knapsack(n, w - wt[n - 1]);
		int op2 = unbounded_knapsack(n - 1, w);
		return dp[n][w] = max(op1, op2);
	}
	return dp[n][w] = unbounded_knapsack(n - 1, w);
}

int main() {
	int n, w; cin >> n >> w;
	for (int i = 0; i < n; i++) cin >> val[i];
	for (int j = 0; j < n; j++) cin >> wt[j];

	cout << unbounded_knapsack(n, w) << "\n";
	return 0;
}