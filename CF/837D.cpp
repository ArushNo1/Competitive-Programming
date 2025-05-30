#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops") 
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

typedef tree<int,null_type,less<int>,rb_tree_tag,
tree_order_statistics_node_update> indexed_set;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;
typedef vector<ll> vll;
typedef pair<ll, ll> pll;

#define endll '\n'

#define all(x) (x).begin(), (x).end()

#define MOD ll(1e9+7)
#define inf int(1e9+1)
#define INF ll(1e18+1)

template <typename T>
inline void fillv(vector<T>& v, int n) {
    for (int i = 0; i < n; ++i) {
        std::cin >> v[i];
    }
}

inline void open(string name){
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
}    

//comment to enable debugging
#define dbg(x)

#ifndef dbg
#define dbg(x) cerr << __LINE__ << ": " << #x << "=" << x << endl;
//edit for specific DS
#include "cp-templates/Debugging/alldebug.h"
#endif

void solve(int num_tc)
{
    ll max5 = 0;
    ll n, k;
    cin >> n >> k;
    vector<pll> a(n);
    for(int i = 0; i < n; i++){
        ll x;
        cin >> x;
        while(x % 2 == 0){
            x /= 2;
            a[i].second++;
        }
        while(x % 5 == 0){
            x /= 5;
            a[i].first++;
            max5++;
        }
    }
    vector<vll> dp(k + 1, vll(max5 + 1, -INF));
    dp[0][0] = 0;
    for(ll i = 0; i < n; i++){
        for(ll j = k; j >= 1; j--){
            for(ll q = max5; q >= a[i].first; q--){
                dp[j][q] = max(dp[j][q], dp[j - 1][q - a[i].first] + a[i].second);
            }
        }
    }
    dbg(a);
    dbg(dp);
    ll ans = 0;
    for(ll i = 0; i <= max5; i++){
        ans = max(ans, min(i, dp[k][i]));
    }
    cout << ans << endll;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);  
    dbg("turn off debugging");
    ll T = 1;
    //cin >> T;
    for(ll t = 0; t < T; t++){
        solve(t+1);
    }
}
