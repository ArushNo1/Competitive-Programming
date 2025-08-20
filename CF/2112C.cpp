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

int maxn = 3 * 1e5 + 5;

void solve(int num_tc)
{
    int n;
    cin >> n;
    vi a(n);
    fillv(a, n);
    auto it = max_element(all(a));
    int biggest = *it;
    a.erase(it);
    n--;
    vvi dp(4, vi(n + 1, 0));
    //number of ways to choose i elements, sum of j
    dp[0][0] = 1;
    for(int i = 0; i < n; i++){
        for(int j = 4; j >= 1; j--){
            for(int k = maxn; k >= 0; k--){
                dp[j][k] += dp[j - 1][k - a[i]];
            }
        }
    }
    ll ans = 0;
    for(int i = biggest + 1; i < maxn; i++){
        ans += dp[2][i] + dp[3][i];
    }
    cout << ans << endll;
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
