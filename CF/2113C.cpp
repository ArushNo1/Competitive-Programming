#include <algorithm>
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
    int n, m, k;
    cin >> n >> m >> k;
    k = k * 2 - 1;
    vvi pref(n + 1, vi(m + 1, 0));
    vector<string> grid(n);
    for(int i = 0; i < n; i++){
        cin >> grid[i];
        for(int j = 0; j < m; j++){
            pref[i + 1][j + 1] = pref[i][j + 1] + pref[i + 1][j] - pref[i][j] + (grid[i][j] == 'g');
        }
    }
    dbg(pref);
    int ans = pref[n][m];
    dbg(ans);
    //find a bomb that deletees the minimum possible
    for(int i= 0; i< n; i++){
        for(int j =0; j < m; j++){
            if(grid[i][j] != '.') continue;
            int x1 = i - (k / 2);
            int y1 = j - (k / 2);
            int x2 = i + (k / 2);
            int y2 = j + (k / 2);
            x1 = max(x1, 0);
            y1 = max(y1, 0);
            x2 = min(x2, n - 1);
            y2 = min(y2, m - 1);
            int cur = pref[x2 + 1][y2 + 1] - pref[x1][y2 + 1] - pref[x2 + 1][y1] + pref[x1][y1];
            ans = min(ans, cur);
        }
    }
    cout << pref[n][m] - ans << endll;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);  
    dbg("turn off debugging");
    ll T = 1;
    cin >> T;
    for(ll t = 0; t < T; t++){
        solve(t+1);
    }
}
