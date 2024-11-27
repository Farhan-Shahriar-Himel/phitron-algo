#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 1e3 + 7;
int dp[N][N];

int32_t main() {
    ios_base::sync_with_stdio(NULL);
    cin.tie(nullptr); cout.tie(nullptr);

    int n; cin >> n;
    vector < int > val(n + 1), wt(n + 1);

    /* The val and wt array are 1 based */
    for (int i = 1; i <= n; i++) cin >> val[i];
    for (int j = 1; j <= n; j++) cin >> wt[j]; 
    int w; cin >> w;
    
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= w; j++) {
            if (wt[i] <= j) {
                int op1 = val[i] + dp[i - 1][j - wt[i]];
                int op2 = dp[i - 1][j];
                dp[i][j] = max(op1, op2);
            }
            else dp[i][j] = dp[i - 1][j];
            ans = max(ans, dp[i][j]);
        }
    }
    cout << ans << '\n';
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= w; j++) {
            cout << dp[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}