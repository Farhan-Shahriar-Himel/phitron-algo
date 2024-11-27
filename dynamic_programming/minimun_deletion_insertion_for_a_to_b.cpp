#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define sq(n) (n)*(n)

const int N = 1e3 + 7;
int dp[N][N];

int32_t main() {

	string a, b; cin >> a >> b;

	int n = a.size(), m = b.size();

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (a[i - 1] == b[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
			else {
				int op1 = dp[i - 1][j];
				int op2 = dp[i][j - 1];
				dp[i][j] = max(op1, op2);
			}
		}
	}
	cout << "To Delete: " << n - dp[n][m] << "\n";
	cout << "To Add: " << m - dp[n][m] << "\n";
	return 0;
}