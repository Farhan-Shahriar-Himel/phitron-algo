#include<bits/stdc++.h>
using namespace std;
#define ll long long

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    auto __solve_testcase = [&]() -> void {
        int n, k; cin >> n >> k; 
        vector < int > a(n);
        int mx = INT_MIN;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            mx = max(mx, a[i]);
        }

        auto possible = [&](ll mid) -> bool {
            if (mx >= mid) return true;
            for (int i = 0; i < n; i++) {
                vector < int > b = a;
                int ind = i;
                ll rem = k;
                ll targ = mid;
                while (1) {
                    if (ind == n or rem < 0) break;
                    if (b[ind] >= targ) return true;
                    rem -= (targ - b[ind]);
                    ind++;
                    targ--;
                }
            }
            return false;
        };

        ll l = 0, r = 1e10, mid, ans = -1;
        while (l <= r) {
            mid = (l + r) / 2ll;
            if (possible(mid)) {
                ans = mid;
                l = mid + 1ll;
            } else r = mid - 1;
        }
        cout << ans << '\n';
    };
    

    int tests; cin >> tests;
    while (tests--) 
    __solve_testcase();
    return 0;
}