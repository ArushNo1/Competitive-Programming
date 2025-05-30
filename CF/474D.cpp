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
    int q, k;
    cin >> q >> k;
    int maxn = 1e5 + 5;
    vector<array<ll, 2>> dp(maxn, {0, 0});
    dp[0][0] = 1;
    for(int i = 1; i < k; i++){
        dp[i][0] = 1;
        dp[i][1] = 0;
    }
    for(int i = k; i < maxn; i++){
        dp[i][0] = (dp[i - 1][0] + dp[i - 1][1]) % MOD;
        dp[i][1] = (dp[i - k][0] + dp[i - k][1]) % MOD;
    }
    vector<ll> ans(maxn, 0);
    for(int i = 1; i < maxn; i++){
        ans[i] = (ans[i - 1] + dp[i][0] + dp[i][1]) % MOD;
    }
    for(int i = 0; i < q; i++){
        int a, b;
        cin >> a >> b;
        cout << (ans[b] - ans[a - 1] + MOD) % MOD << endll;
    }
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
