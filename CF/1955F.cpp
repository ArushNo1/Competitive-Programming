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

int lim = 200;

vector<vector<vector<int>>> dp(lim + 1, vector<vector<int>>(lim + 1, vector<int>(lim + 1, 0)));

void solve(int num_tc)
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    cout << dp[a][b][c] + d / 2 << endll;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);  
    dbg("turn off debugging");
    
    
    for(int i = 0; i <= lim; i++){
        for(int j = 0; j <= lim; j++){
            for(int k = 0; k <= lim; k++){
                if(i == 0 && j == 0 && k == 0){
                    dp[i][j][k] = 0;
                    continue;
                }
                if(i > 0) dp[i][j][k] = dp[i - 1][j][k];
                if(j > 0) dp[i][j][k] = max(dp[i][j][k], dp[i][j - 1][k]);
                if(k > 0) dp[i][j][k] = max(dp[i][j][k], dp[i][j][k - 1]);
                if(((j + k) % 2 == 0) && ((i + k) % 2 == 0)){
                    dp[i][j][k]++;
                }
            }
        }
    }
    
    dbg(dp);
    
    
    
    ll T = 1;
    cin >> T;
    for(ll t = 0; t < T; t++){
        solve(t+1);
    }
}
