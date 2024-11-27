#include<bits/stdc++.h>
using namespace std;

const int N = 1e3 + 7;
int dp[N][N];

int main() {
	string a, b; cin >> a >> b;

	for (int i = 1; i <= a.size(); i++) {
		for (int j = 1; j <= b.size(); j++) {
			if (a[i - 1] == b[j - 1]) dp[i][j] = 1 + dp[i - 1][j - 1];
			else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}
	cout << dp[a.size()][b.size()] << "\n";

	int i = a.size(), j = b.size();
	string ans = "";

	while (i != 0 and j != 0) {
		if (a[i - 1] == b[j - 1]) {
			ans += a[i - 1];
			i--, j--;
		}
		else {
			if (dp[i - 1][j] >= dp[i][j - 1]) i--;
			else j--;
		}
	}
	reverse(ans.begin(), ans.end());
	cout << ans << "\n";
	return 0;
}