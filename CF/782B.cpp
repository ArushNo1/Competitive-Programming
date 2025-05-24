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
typedef long long ll;
typedef vector<ll> vll;
typedef pair<ll, ll> pll;

#define endll '\n'

#define all(x) (x).begin(), (x).end()

#define MOD ll(1e9 + 7)
#define inf int(1e9 + 1)
#define INF ll(1e18 + 1)

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
    vector<ll> pos(n);
    fillv(pos, n);
    vector<double> speed(n);
    fillv(speed, n);
    auto timetoget = [&](double x) {
        double m = 0;
        for (int i = 0; i < n; i++) {
            m = max(m, abs(x - pos[i]) / speed[i]);
        }
        return m;
    };
    double EPS = 1e-9;
    double lo = *min_element(all(pos));
    double hi = *max_element(all(pos));
    while (hi - lo > (EPS)) {
        double mid = lo + (hi - lo) / 2;
        double mid2 = mid + (hi - mid) / 10.0;
        double delta = timetoget(mid2) - timetoget(mid);
        if (abs(delta) < EPS) {
            cout << fixed << setprecision(12)
                 << timetoget(mid + (mid2 - mid) / 2);
            return;
        }
        if (delta > 0) {
            hi = mid2;
        } else {
            lo = mid;
        }
    }
    cout << fixed << setprecision(12) << timetoget(lo + (hi - lo) / 2) << endll;
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
