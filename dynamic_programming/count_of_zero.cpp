#include<bits/stdc++.h>
using namespace std;

const int N = 1e3 + 7;
vector < vector < int > > dp(N, vector < int > (N, -1));
int a[N];
int n, k;

int count_of_zero(int n, int w) {
	if (w == 0) return 1;
	if (n <= 0 or w < 0) return 0;
	if (dp[n][w] != -1) return dp[n][w];

	int op1 = count_of_zero(n - 1, w - a[n - 1]);
	int op2 = count_of_zero(n - 1, w);

	return dp[n][w] = op1 + op2;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	cin >> k;
	
	cout << count_of_zero(n, k) << "\n";
	return 0;
}
