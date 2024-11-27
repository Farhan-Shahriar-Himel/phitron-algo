#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 1e3 + 10;
int dp[N], val[N];

// int Ways(int n) {
// 	if (!n) return 0;
// 	if (DP[n] != -1) return DP[n];
// 	int ans = 0;
// 	for (int i = 1; i <= n; i++) {
// 		if (n - i >= 0)
// 			ans = max(ans, Ways(n - i) + val[i - 1]);
// 	}
// 	return DP[n] = ans;
// }

int main() {
	int n; cin >> n;
	for (int i = 1; i <= n; i++) cin >> val[i];

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i - j >= 1)
			int op = dp[i - j] + val[i - 1];
		}
	}
	cout << dp[n] << "\n";
	return 0;
}