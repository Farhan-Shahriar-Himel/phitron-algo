#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 1e5 + 7;
vector < ll > height(N);
vector < ll > dp(N, -1);

int jump(int n) {

	if (n == 1) return 0;
	if (n == 2) return abs(height[n] - height[n - 1]);
	if (dp[n] != -1) return dp[n];
	int ans1 = jump(n - 1) + abs(height[n] - height[n - 1]);
	int ans2 = jump(n - 2) + abs(height[n] - height[n - 2]);
	return dp[n] = min(ans1, ans2);
}

int32_t main() {
	int n; cin >> n;
	for (int i = 1; i <= n; i++) cin >> height[i];
	int ans = jump(n);
	cout << ans << '\n';
	return 0;
}