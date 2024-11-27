#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 1e7 + 7;
vector < ll > dp(N, 1);

// ll fibo(int n) {
// 	if (!n or n == 1) return 1;
// 	if (dp[n] != -1) return dp[n];

// 	return dp[n] = fibo(n-1) + fibo(n-2);
// }

int main() {
	int n; cin >> n;
	// cout << fibo(n) << "\n";

	for (int i = 2; i <= n; i++) 
		dp[i] = dp[i - 1] + dp[i - 2];

	cout << dp[n] << '\n';
	return 0;
}