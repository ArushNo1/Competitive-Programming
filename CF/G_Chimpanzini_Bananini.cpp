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

struct bananini {
    deque<ll> a;
    ll sum_all = 0;
    ll rizz = 0;
    int n = 0;
    bool reverse = false;
    bananini(bool back) : reverse(back) {}

    ll add(ll x) {
        n++;
        sum_all += x;
        a.push_back(x);
        rizz += n * x;
        return rizz;
    }

    ll radd(ll x) {
        n++;
        sum_all += x;
        a.push_front(x);
        rizz += sum_all;
        return rizz;
    }

    ll rotate() {
        ll x = a.back();
        a.pop_back();
        a.push_front(x);

        rizz -= (n - 1) * x;
        rizz += (sum_all - x);

        return rizz;
    }

    ll rrotate() {
        ll x = a.front();
        a.pop_front();
        a.push_back(x);

        rizz -= (sum_all - x);
        rizz += (n - 1) * x;

        return rizz;
    }
};

void solve(int num_tc) {
    int q;
    cin >> q;
    bananini a(false);
    bananini b(true);
    for (int i = 0; i < q; i++) {
        int s;
        cin >> s;
        if (s == 3) {
            ll x;
            cin >> x;
            std::cout << a.add(x) << endll;
            b.radd(x);
        } else if (s == 1) {
            std::cout << a.rotate() << endll;
            b.rrotate();
        } else {
            swap(a, b);
            std::cout << a.rizz << endll;
        }
        dbg(b.rizz);
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    std::cout.tie(0);
    dbg("turn off debugging");
    ll T = 1;
    cin >> T;
    for (ll t = 0; t < T; t++) {
        solve(t + 1);
    }
}
