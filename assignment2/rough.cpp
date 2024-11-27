#include<bits/stdc++.h>
using namespace std;
 
int main() {
    int n; cin >> n;
    cout << ((n & 1) or (n == 2) ? "NO\n" : "YES\n");
    return 0;
}