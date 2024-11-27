#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 1e3 + 7;
int val[N], wt[N];
int dp[N][N];

int main() {
	int n, w; cin >> n >> w;
	for (int i = 1; i <= n; i++) cin >> val[i];
	for (int i = 1; i <= n; i++) cin >> wt[i];

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= w; j++) {
			
			if (j - wt[i] >= 0) {
				int op1 = val[i] + dp[i][j - wt[i]];
				int op2 = dp[i - 1][j];
				dp[i][j] = max(op1, op2);	
			} else dp[i][j] = dp[i - 1][j];
		}
	}
	cout << dp[n][w] << "\n";
	return 0;
}