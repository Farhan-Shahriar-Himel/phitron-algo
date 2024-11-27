#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define sq(n) (n)*(n)

vector < int > merge(vector < int > left, vector < int > right) {
	vector < int > ans(left.size() + right.size());
	
	int lp = 0, rp = 0;

	left.push_back(INT_MIN);
	right.push_back(INT_MIN);

	
	for (int i = 0; i < left.size() + right.size() - 2; i++) 
		left[lp] > right[rp] ? ans[i] = left[lp++] : ans[i] = right[rp++];

	return ans;
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n; cin >> n; vector < int > v1(n);
	for (int i = 0; i < n; i++) cin >> v1[i];
	int m; cin >> m; vector < int > v2(m);
	for (int i = 0; i < m; i++) cin >> v2[i];

	vector < int > ans = merge(v1, v2);

	for (int i = 0; i < ans.size(); i++) cout << ans[i] << ' ';
	return 0;
}
