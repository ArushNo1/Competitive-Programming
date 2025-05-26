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
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    vi ctowhite(m, 0);
    vi ctoblack(m, 0);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            char c;
            cin >> c;
            if(c == '.'){
                ctoblack[j]++;
            }
            else{
                ctowhite[j]++;
            }
        }
    }
    vector<vector<ll>> dp(m + 1, vector<ll>(2, inf));
    vi totalcblack(m + 1, 0);
    vi totalcwhite(m + 1, 0);
    for(int i = 0; i < m; i++){
        totalcblack[i + 1] = totalcblack[i] + ctoblack[i];
        totalcwhite[i + 1] = totalcwhite[i] + ctowhite[i];
    }
    dp[0][0] = 0;
    dp[0][1] = 0;
    // for(int i = 1; i <= x; i++){
    //     dp[i][0] = dp[i - 1][0] + ctoblack[i - 1];
    //     dp[i][1] = dp[i - 1][1] + ctowhite[i - 1];
    // }
    for(int i = x; i <= m; i++){
        for(int s = x; s <= y; s++){
            if(i - s < 0) break;
            dp[i][0] = min(dp[i][0], dp[i - s][1] + totalcblack[i] - totalcblack[i - s]);
            dp[i][1] = min(dp[i][1], dp[i - s][0] + totalcwhite[i] - totalcwhite[i - s]);
        }
    }
    cout << min(dp[m][0], dp[m][1]) << endll;
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
