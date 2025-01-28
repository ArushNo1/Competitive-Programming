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
#define maxeq(a, b) a = max<decltype(a)>(a, b)
#define mineq(a, b) a = min<decltype(a)>(a, b)

#define MOD ll(1e9 + 7)
#define inf int(1e9 + 1)
#define INF ll(1e18 + 1)
#define EPS ld(1e-9)

template <typename T> inline void fillv(vector<T> &v, int n) {
    for (int i = 0; i < n; ++i) {
        std::cin >> v[i];
    }
}
template <typename T, typename U>
inline void fillv(vector<pair<T, U>> &v, int n, bool inv = false) {
    if (inv) {
        for (int i = 0; i < n; ++i) {
            cin >> v[i].second >> v[i].first;
        }
        return;
    }
    for (int i = 0; i < n; ++i) {
        cin >> v[i].first >> v[i].second;
    }
    return;
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
#include <alldebug.h>
#endif

ll length(ll n) {
    ll bits = 64 - __builtin_clzll(n);
    return (1LL << bits) - 1;
}

ll check(ll n, ll i, ll len) {
    if (n <= 1) {
        return n;
    }
    if (2 * i == len - 1) {
        return n % 2;
    }
    n /= 2;
    len /= 2;
    if (i > len) {
        i = i - len - 1;
    }
    return check(n, i, len);
}

void solve(int num_tc) {
    ll n, l, r;
    cin >> n >> l >> r;
    l--;
    r--;
    ll ans = 0;
    ll len = length(n);
    for (ll i = l; i <= r; i++) {
        // cerr << "i: " << i << endll;
        ll x = check(n, i, len);
        // cerr << "x: " << x << endll;
        ans += x;
    }
    cout << ans << endll;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll T = 1;
    // cin >> T;
    for (ll t = 0; t < T; t++) {
        solve(t + 1);
    }
}
