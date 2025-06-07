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
    int hcount, gcount;
    cin >> hcount >> gcount;
    vector<pll> h(hcount + 1);
    vector<pll> g(gcount + 1);
    for(int i = 1; i <= hcount; i++){
        cin >> h[i].first >> h[i].second;
    }
    for(int i = 1; i <= gcount; i++){
        cin >> g[i].first >> g[i].second;
    }
    dbg(h);
    dbg(g);
    auto dist = [](pll a, pll b) -> ll {
        return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
    };
    vector<vector<pll>> dp(hcount + 1, vector<pll>(gcount + 1, {INF, INF}));
    dp[1][0] = {0, inf};
    for(int i = 1; i <= hcount; i++){
        for(int j = 0; j <= gcount; j++){
            //visited i h's and j g's
            if(i < hcount) dp[i + 1][j].first = min(dp[i + 1][j].first, dp[i][j].first + dist(h[i], h[i + 1]));
            if(i < hcount) dp[i + 1][j].first = min(dp[i + 1][j].first, dp[i][j].second + dist(g[j], h[i + 1]));
            if(j < gcount) dp[i][j + 1].second = min(dp[i][j + 1].second, dp[i][j].first + dist(h[i], g[j + 1]));
            if(j < gcount) dp[i][j + 1].second = min(dp[i][j + 1].second, dp[i][j].second + dist(g[j], g[j + 1]));
        }
    }
    dbg(dp);
    cout << dp[hcount][gcount].first << endll;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);  
    dbg("turn off debugging");
    open("checklist");
    ll T = 1;
    //cin >> T;
    for(ll t = 0; t < T; t++){
        solve(t+1);
    }
}
