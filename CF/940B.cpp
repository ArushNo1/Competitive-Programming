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

ll n, k, a, b;
map<ll, ll> memo;

ll dp(ll x){
    dbg(x);
    if(memo.find(x) != memo.end()) return memo[x];
    if(x == 1){
        return 0;
    }
    if(x == k){
        return min((x - 1) * a, b);
    }
    if(x < k){
        memo[x] = a * (x - 1);
        return memo[x];
    }
    if(x % k == 0){
        ll diff = x - x / k;
        memo[x] = dp(x / k) + min(b, diff * a); 
        return memo[x];
    }
    ll res = x % k;
    memo[x] = dp(x - res) + a * res;
    return memo[x];
}

void solve(int num_tc)
{
    cin >> n >> k >> a >> b;
    if(k == 1){
        cout << (n - 1) * a << endll;
        return;
    }
    ll ans = dp(n);
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
