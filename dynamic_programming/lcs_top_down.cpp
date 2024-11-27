#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 1e3 + 7;
vector < vector < int > > dp(N, vector < int > (N, -1));
string a, b;

int lcs(int n, int m) {
	if (!n or !m) return 0;
	if (dp[n][m] != -1) return dp[n][m];

	if (a[n - 1] == b[m - 1]) return dp[n][m] = lcs(n - 1, m - 1) + 1;
	else {
		int op1 = lcs(n - 1, m);
		int op2 = lcs(n, m - 1);
		return dp[n][m] = max(op1, op2);
	}
}

int main() {
	cin >> a >> b;
	cout << lcs(a.size(), b.size()) << "\n";
	return 0;
}