#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

typedef tree<int, null_type, less<int>, rb_tree_tag,
             tree_order_statistics_node_update>
    indexed_set;

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

#define MOD ll(1e9 + 7)
#define inf int(1e9 + 1)
#define INF ll(1e18 + 1)
#define EPS ld(1e-9)

template <typename T> inline void fillv(vector<T> &v, int n) {
    for (int i = 0; i < n; ++i) {
        std::cin >> v[i];
    }
}

inline void open(string name) {
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
}

// comment to enable debugging
#define dbg(x)

#ifndef dbg
#define dbg(x) cerr << __LINE__ << ": " << #x << "=" << x << endl;
// edit for specific DS
#include "cp-templates/Debugging/alldebug.h"
#endif

void solve(int num_tc) {
    int n;
    cin >> n;
    vi t(n), x(n), y(n);
    for(int i = 0; i < n; i++) {
        cin >> t[i] >> x[i];
        if(t[i] == 2) {
            cin >> y[i];
        }
    }
    vi ans;
    vi res(5e5 + 1);
    iota(all(res), 0);
    for(int i = n - 1; i >= 0; i--) {
        if(t[i] == 1){
            ans.push_back(res[x[i]]);
        }
        else {
            res[x[i]] = res[y[i]];
        }
    }
    reverse(all(ans));
    for(int i : ans) {
        cout << i << " ";
    }
    cout << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    dbg("turn off debugging");
    ll T = 1;
    // cin >> T;
    for (ll t = 0; t < T; t++) {
        solve(t + 1);
    }
}
