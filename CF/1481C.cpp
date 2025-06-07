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
    int n, m;
    cin >> n >> m;
    vi orig(n);
    for (int i = 0; i < n; i++) {
        cin >> orig[i];
        orig[i]--;
    }
    vector<vi> needed(n);
    vi wanted(n);
    for (int i = 0; i < n; i++) {
        cin >> wanted[i];
        wanted[i]--;
        if (wanted[i] != orig[i]) {
            needed[wanted[i]].push_back(i);
        }
    }
    vi painters(m);
    for (int i = 0; i < m; i++) {
        cin >> painters[i];
        painters[i]--;
    }
    vi assignments(m);
    int dump = -1;
    if (needed[painters[m - 1]].empty()) {
        for (int i = 0; i < n; i++) {
            if (painters[m - 1] == wanted[i]) {
                assignments[m - 1] = i;
                dump = i;
                break;
                ;
            }
        }
    }
    else{
        assignments[m - 1] = needed[painters[m - 1]].back();
        needed[painters[m - 1]].pop_back();
        dump = assignments[m - 1];
    }
    if(dump == -1) {
        cout << "NO" << endll;
        return;
    }
    for (int i = 0; i < m - 1; i++) {
        if (needed[painters[i]].empty()) {
            assignments[i] = dump;
        } else {
            assignments[i] = needed[painters[i]].back();
            needed[painters[i]].pop_back();
        }
    }
    for (int i = 0; i < n; i++) {
        if (needed[i].size() > 0) {
            cout << "NO" << endll;
            return;
        }
    }
    cout << "YES" << endll;
    for (int i = 0; i < m; i++) {
        cout << assignments[i] + 1 << " ";
    }
    cout << endll;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    dbg("turn off debugging");
    ll T = 1;
    cin >> T;
    for (ll t = 0; t < T; t++) {
        solve(t + 1);
    }
}
