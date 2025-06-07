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
    int n, m;
    cin >> n >> m;
    vector<pll> bess(n + 1);
    vector<pll> fj(m + 1);
    cin >> bess[0].first >> bess[0].second;
    cin >> fj[0].first >> fj[0].second;
    for(int i = 1; i <= n; i++){
        char c;
        cin >> c;
        switch(c){
            case 'N':
                bess[i].first = bess[i - 1].first;
                bess[i].second = bess[i - 1].second + 1;
                break;
            case 'S':
                bess[i].first = bess[i - 1].first;
                bess[i].second = bess[i - 1].second - 1;
                break;
            case 'E':
                bess[i].first = bess[i - 1].first + 1;
                bess[i].second = bess[i - 1].second;
                break;
            case 'W':
                bess[i].first = bess[i - 1].first - 1;
                bess[i].second = bess[i - 1].second;
                break;
        }
    }
    for(int i = 1; i <= m; i++){
        char c;
        cin >> c;
        switch(c){
            case 'N':
                fj[i].first = fj[i - 1].first;
                fj[i].second = fj[i - 1].second + 1;
                break;
            case 'S':
                fj[i].first = fj[i - 1].first;
                fj[i].second = fj[i - 1].second - 1;
                break;
            case 'E':
                fj[i].first = fj[i - 1].first + 1;
                fj[i].second = fj[i - 1].second;
                break;
            case 'W':
                fj[i].first = fj[i - 1].first - 1;
                fj[i].second = fj[i - 1].second;
                break;
        }
    }
    dbg(bess);
    dbg(fj);
    auto dist = [](pll a, pll b) -> ll {
        return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
    };
    vector<vector<ll>> dp(n + 1, vector<ll>(m + 1, INF));
    dp[0][0] = 0;
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= m; j++){
            ll result = INF;
            if(i > 0){
                result = min(result, dp[i - 1][j]);
            }
            if(j > 0){
                result = min(result, dp[i][j - 1]);
            }
            if(i > 0 && j > 0){
                result = min(result, dp[i - 1][j - 1]);
            }
            dp[i][j] = min(dp[i][j], result + dist(bess[i], fj[j]));
        }
    }
    cout << dp[n][m] << endll;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);  
    dbg("turn off debugging");
    ll T = 1;
    open("radio");
    //cin >> T;
    for(ll t = 0; t < T; t++){
        solve(t+1);
    }
}
