#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 1e3 + 7;
vector < vector < int > > dp(N, vector < int > (N, 0));
int wt[N];

int main() {
    int n; cin >> n;
    for (int i = 1; i <= n; i++) cin >> wt[i];
    int w; cin >> w;
    dp[0][0] = true;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= w; j++) {
            if (j - wt[i] >= 0) {
                int op1 = dp[i][j - wt[i]];
                int op2 = dp[i - 1][j];
                dp[i][j] = op1 + op2; 
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    cout << dp[n][w] << "\n";
    return 0;
}