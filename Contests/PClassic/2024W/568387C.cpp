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
typedef pair<int, int> ii;
typedef long long ll;
typedef vector<ll> vll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef vector<bool> vb;

#define endll '\n'

#define all(x) (x).begin(), (x).end()

#define MOD ll(1e9+7)
#define inf int(1e9+1)
#define INF ll(1e18+1)
#define EPS ld(1e-9)

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
    int n;
    cin >> n;
    vll d(n);
    fillv(d, n);

    auto eval = [&](ll vo){
        vector<vll> dp(n + 1, vll(2, -INF));
        dp[0][0] = vo;
        dp[0][1] = 2 * vo;
        //dp[i][j] is dune i, j doubles;
        for(int i = 1; i <= n; i++){
            dp[i][0] = dp[i - 1][0] + d[i - 1];
            if(dp[i][0] <= 0) dp[i][0] = -INF;
            dp[i][1] = max(dp[i - 1][0] * 2, dp[i - 1][1]) + d[i - 1];
            if(dp[i][1] <= 0) dp[i][1] = -INF;
            if(dp[i][1] == -INF && dp[i][0] == -INF){
                dbg(dp);
                return false;
            }
        }
        dbg(dp);
        return true;
    };
    ll low = 1, high = 1e15;
    while(low < high){
        ll mid = low + (high - low) / 2;
        if(eval(mid)){
            high = mid;
        }
        else{
            low = mid + 1;
        }
    }
    cout << low << endll;
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
