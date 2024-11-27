#include<bits/stdc++.h>
using namespace std;
 /*\_____________/___F@Rh@N_Sh@hR!@R___\_____________\*/
#define nl        '\n'
#define ll        long long int
#define pb        push_back
#define pob       pop_back
#define F         first
#define S         second
#define ins       insert
#define elif      else if
#define yes       cout << "YES" << nl
#define no        cout << "NO" << nl
#define vct       vector
#define pr        pair
#define all(x)             x.begin(), x.end()
#define loop(i,n)          for(int i=0; i<n; i++)
#define Loop(i, x, n, j)   for(int i=x; x<n?i<=n:i>=n; i+=j)

typedef vct<int>        vi;
typedef vct<ll>         vl;
typedef pr<int, int>    pii;
typedef pr<ll,ll>       pll;
typedef vct<pii>        vpii;
typedef vct<pll>        vpll;
typedef vct<vi>         vvi;
typedef vct<vl>         vvl;
#define PI 3.1415926535897932384626
#define MOD LLONG_MAX
const int N = 1e7+10;
const int INF = 1e9+10;

ll gcd(ll a, ll b);
ll lcm(ll a, ll b);
ll binexp(ll base, ll exp);
ll root(ll n);
 /*\_____________/___F@Rh@N_Sh@hR!@R___\_____________\*/


int main()
{
    ios_base::sync_with_stdio(NULL);
    cin.tie(0); cout.tie(0);

    auto __solve_testcase = [&]() -> void {
    	cout << "hello" << "\n";
    };

    int t=1;
    cin >> t;
    while (t--)
    __solve_testcase();
    return 0;
}

ll gcd(ll a, ll b){if(a==0) return b;else return gcd(b%a, a);}
ll lcm(ll a, ll b){return (a*b)/gcd(a,b);}
ll binexp(ll base, ll exp){
    ll ans=1;
    while(exp){
        if(exp&1){ans = (ans * base) % MOD;}
        base = (base * base) % MOD;
        exp >>= 1;
    }
    return ans;
}
ll root(ll n){
    ll l=0, r=n, mid;
    while(r-l>1){
        mid = (r+l)/2;
        if(mid*mid < n) l = mid;
        else if(mid*mid > n) r = mid-1;
        else break;
    }
    if(mid*mid == n) return mid;
    else if(r*r == n) return r;
    return l;
}