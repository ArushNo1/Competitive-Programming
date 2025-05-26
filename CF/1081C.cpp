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

#define MOD ll(998244353)
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
    ll n, m, k;
    cin >> n >> m >> k;
    if(k == 0){
        cout << m << endll;
        return;
    }
    if(n == 1){
        cout << m << endll;
        return;
    }
    if(n == 2){
        if(k == 1){
            cout << m * (m - 1) << endll;
        }
        else{
            cout << m << endll;
        }
        return;
    }
    vector<vll> dp(n + 1, vll(k + 1, 0));
    dp[1][0] = m;
    for(int i = 2; i <= n; i++){
        for(int j = 0; j <= k; j++){
            dp[i][j] = dp[i - 1][j];
            if(j > 0){
                dp[i][j] += dp[i - 1][j - 1] * (m - 1);
                dp[i][j] %= MOD;
            }
        }
    }
    dbg(dp);
    cout << dp[n][k] << endll;
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
