#include<bits/stdc++.h>
using namespace std;

const int N = 1e3 + 7;
vector < vector < int > > dp(N, vector < int > (N, 0));

int main() {
	int n; cin >> n;
	vector < int > a(n + 1);
	for (int i = 1; i <= n; i++) cin >> a[i];
	int k; cin >> k;
	
	dp[0][0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= k; j++) {
			if (j - a[i] >= 0) {\
				bool op1 = dp[i - 1][j - a[i]];
				bool op2 = dp[i - 1][j];
				dp[i][j] = op1 || op2;
			}
			else dp[i][j] = dp[i - 1][j];
		}	
	}
	//cout << dp[n][k] << "\n";
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= k; j++) {
			cout << dp[i][j] << ' ';
		}
		cout << '\n';
	}
}