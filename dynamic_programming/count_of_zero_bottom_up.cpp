/* give input
5
0 0 0 0 7
7
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long

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
			if (j - a[i] >= 0) {
				int op1 = dp[i - 1][j - a[i]];
				int op2 = dp[i - 1][j];
				dp[i][j] = op1 + op2;
			}
			else dp[i][j] = dp[i - 1][j];
		}
	}
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= k; j++) {
			cout << dp[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}