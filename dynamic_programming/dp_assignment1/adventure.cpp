#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define sq(n) (n)*(n);

const int N = 1e3 + 7;
vector < vector < int > > dp(N, vector < int > (N, 0));
int wt[N], eq[N];

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    auto __solve_testcase = [&]() -> void {

            int n, w; cin >> n >> w;
            for (int i = 1; i <= n; i++) cin >> wt[i];
            for (int j = 1; j <= n; j++) cin >> eq[j];

            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= w; j++) {
                    int op1 = 0, op2 = 0;
                    if (j - wt[i] >= 0)
                        op1 = eq[i] + dp[i - 1][j - wt[i]];
                    op2 = dp[i - 1][j];
                    dp[i][j] = max(op1, op2);
                }
            }
            cout << dp[n][w] << "\n";
    };

    int tests; cin >> tests;
    while (tests--) 
    __solve_testcase();
    return 0;
}