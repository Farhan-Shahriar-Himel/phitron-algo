#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define sq(n) (n)*(n)

const int N = 1e3 + 7;
int dp[N][N];
string a, b;

int32_t main() {
	ios_base::sync_with_stdio(NULL);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> a >> b;

	for (int i = 1; i <= a.size(); i++) {
		for (int j = 1; j <= b.size(); j++) {
			if (a[i - 1] == b[j - 1]) dp[i][j] = 1 + dp[i - 1][j - 1];
			else {
				int op1 = dp[i - 1][j];
				int op2 = dp[i][j - 1];
				dp[i][j] = max(op1, op2);
			}
		}
	}
	cout << dp[a.size()][b.size()] << "\n";
	return 0;
}