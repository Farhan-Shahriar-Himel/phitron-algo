#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 1e3 + 7;
int box[N];
int dp[N][N];

int32_t main() {
    ios_base::sync_with_stdio(NULL);
    cin.tie(nullptr); cout.tie(nullptr);

    auto __ = [&]() -> void {

            memset(dp, false, sizeof(dp));
            int n; cin >> n;
            int sum = 0;
            for (int i = 1; i <= n; i++) {
                cin >> box[i];
                sum += box[i];
            }
            if (sum & 1) {
                cout << "NO\n";
                return;
            }
            sum /= 2;
            dp[0][0] = true;
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= sum; j++) {
                    bool op1 = false, op2 = false;
                    if (j - box[i] >= 0) op1 = dp[i - 1][j - box[i]];
                    op2 = dp[i - 1][j];
                    dp[i][j]  = op1 or op2;
                }
            }
            cout << (dp[n][sum] ? "YES" : "NO") << "\n";
    };

    int _; cin >> _;
    while (_--)
    __();
    return 0;
}