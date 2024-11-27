#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N = 21;
vector < vector < int > > dp(N, vector < int > (N, 0));

int32_t main() {
	int n, d; cin >> n >> d;
	vector < int > a(n + 1);
	int s = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		s += a[i];
	}

	if ((d + s) & 1) {
		cout << "NO" << "\n";
		return 0;
	}

	dp[0][0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= s; j++) {
			if (j - a[i] >= 0) {
				int op1 = dp[i - 1][j - a[i]];
				int op2 = dp[i - 1][j];
				dp[i][j] = op1 + op2;
			} else dp[i][j] = dp[i - 1][j];
		}
	}
	
	cout << (dp[n][s] ? "YES": "NO") << "\n";
	return 0;
}