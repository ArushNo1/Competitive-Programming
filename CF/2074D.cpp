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

template<typename T>
T last_true(T lo, T hi, std::function<bool(T)> f) {
    lo--;
    while (lo < hi) {
        T mid = lo + (hi - lo + 1) / 2;
        if (f(mid)) {
            lo = mid;
        } else {
            hi = mid - 1;
        }
    }
    return lo;
}


void solve(int num_tc)
{
    int n, m;
    cin >> n >> m;
    vll centers(n), radii(n);
    fillv(centers, n);
    fillv(radii, n);
    map<ll, ll> yvals;
    for(int i = 0; i < n; i++){
        dbg(i);
        for(int x = centers[i] - radii[i]; x <= centers[i] + radii[i]; x++){
            dbg(x);
            auto eval = [&](ll y){
                return (x - centers[i]) * (x - centers[i]) + y * y <= radii[i] * radii[i];
            };
            ll ylo = last_true<ll>(0, 3 * m, eval);
            dbg(ylo);
            if(ylo == -1) continue;
            yvals[x] = max(yvals[x], 2 * ylo + 1);
        }
    }
    ll ans = 0;
    for(auto [x, y] : yvals){
        ans += y;
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
