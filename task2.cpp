#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define sq(n) (n)*(n)

int32_t main() {
	ios_base::sync_with_stdio(NULL); 
	cin.tie(0); cout.tie(0);

	int n; cin >> n; int a[n];
	for (int i = 0; i < n; i++) cin >> a[i];
	int x; cin >> x;

	int l = 0, r = n - 1, mid;
	while (l <= r) {
		mid = (l + r) / 2;
		if (a[mid] == x) {
			cout << mid << '\n';
			return 0;
		} 
		else if (a[mid] < x) l = mid + 1;
		else r= mid - 1;
	}
	cout << "Not Found\n";
	return 0;
}