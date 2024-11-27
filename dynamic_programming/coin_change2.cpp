#include<bits/stdc++.h>
using namespace std;

const int N = 1e3 + 7;
const int inf = 1e9 + 7;
vector < vector < int > > dp(N, vector < int > (N, inf));
int wt[N];

int main() {
	int n; cin >> n;
	for (int i = 1; i <= n; i++) cin >> wt[i];
	int w; cin >> w;

	dp[0][0] = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= w; j++) {
			if (j - wt[i] >= 0) {
				int op1 = dp[i][j - wt[i]] + 1;
				int op2 = dp[i - 1][j];
				dp[i][j] = min(op1, op2);
			} else dp[i][j] = dp[i - 1][j];
		}
	}
	cout << dp[n][w] << "\n";
	return 0;

}