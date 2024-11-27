#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 1e5 + 7;
int cost[N], weight[N];

int knapsack(int n, int w) {
	if (n == 0 or w == 0) return 0;
	int op1 = 0, op2 = 0;
	if (weight[n - 1] <= w) op1 = knapsack(n - 1, w - weight[n - 1]) + cost[n -1];
	op2 = knapsack(n - 1, w);
	return max(op1, op2);
}

int32_t main() {
	ios_base::sync_with_stdio(NULL);
	cin.tie(nullptr); cout.tie(nullptr);

	int n; cin >> n;
	for (int i = 0; i < n; i++) cin >> cost[i];
	for (int i = 0; i < n; i++) cin >> weight[i];
	int w; cin >> w;

	//int ans = knapsack(n, w);
	cout << "hello" << '\n';
	return 0;
}