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
    ll t, a, b;
    cin >> t >> a >> b;
    if(a > b) swap(a, b);
    //dp[i][j] is if it's possible to get i fullness with j halvings
    //vector<vb> dp(t+1, vb(2, false));
    //dp[0][0] = true;
    vb dp2(t+1, false);
    dp2[0] = true;
    for(int i = a; i <= t; i++){
        //dp[i][0] = dp[i][0] || dp[i - a][0];
        dp2[i] = dp2[i] || dp2[i - a];
        //if(i >= b) dp[i][0] = dp[i][0] || dp[i - b][0];
        if(i >= b) dp2[i] = dp2[i] || dp2[i - b];
    }
    if(dp2[t]) {
        cout << t << endll;
        return;
    }
    for(int i = 0; i <= t; i++){
        //if(i >= a) dp[i][1] = dp[i][0] || dp[i - a][1];
        if(i >= a) dp2[i] = dp2[i] || dp2[i - a];
        //if(i >= b) dp[i][1] = dp[i][0] || dp[i - b][1];
        if(i >= b) dp2[i] = dp2[i] || dp2[i - b];
        //if(2 * i <= t) dp[i][1] = dp[i][1] || dp[2 * i][0];
        if(2 * i <= t) dp2[i] = dp2[i] || dp2[2 * i];
        //if(2 * i < t) dp[i][1] = dp[i][1] || dp[2 * i + 1][0];
        if(2 * i < t) dp2[i] = dp2[i] || dp2[2 * i + 1];
    }
    for(int i = t; i >= 0; i--){
        if(dp2[i]){
            cout << i << endll;
            return;
        }
    }
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);  
    dbg("turn off debugging");
    //open("feast");
    ll T = 1;
    //cin >> T;
    for(ll t = 0; t < T; t++){
        solve(t+1);
    }
}
