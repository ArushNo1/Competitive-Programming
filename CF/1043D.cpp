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
    vvi grid(m, vi(n, 0));
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cin >> grid[i][j];
            grid[i][j]--;
        }
    }
    vi remap(n);
    for(int i = 0; i < n; i++){
        remap[grid[0][i]] = i;
    }
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            grid[i][j] = remap[grid[i][j]];
        }
    }
    vi rlen(n, n);
    for(int i = 0; i < m; i++){
        int cur = 0;
        for(int j = 0; j < n; j++){
            if(cur < j) cur++;
            while(cur < n - 1 && grid[i][cur + 1] == grid[i][cur] + 1){
                cur++;
            }
            rlen[grid[i][j]] = min(rlen[grid[i][j]], grid[i][cur]);
        }
    }
    ll ans = 0;
    ll cur = 0;
    while(cur < n){
        int cur2 = rlen[cur] - cur + 1;
        ans += ll(cur2) * (cur2 + 1ll) / 2ll;
        cur = rlen[cur] + 1;
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
