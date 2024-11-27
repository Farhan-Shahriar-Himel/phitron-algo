#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define sq(n) (n)*(n);

const int N = 1e3 + 7;
int dp[N][N];

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	string a, b; cin >> a >> b;
	int ans = 0, x, y;

	for (int i = 1; i <= a.size(); i++) {
		for (int j = 1; j <= b.size(); j++) {
			if (a[i - 1] == b[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
			else dp[i][j] = 0;
			if (ans < dp[i][j]) ans = dp[i][j], x = i, y = j;
		}
	}
	cout << ans << "\n";

	int i = x, j = y;
	int lp = ans;
	string s = "";
	while (lp--) {
		s += a[i - 1];
		i--, j--;
	}
	reverse(s.begin(), s.end());
	cout << s << "\n";
	return 0;
}