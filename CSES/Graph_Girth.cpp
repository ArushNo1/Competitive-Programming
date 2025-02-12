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

vvi adj;
int min_cycle(int start){
    int n = adj.size();
    vi dist(n, inf);
    dist[start] = 0;
    queue<int> bfs;
    bfs.push(start);
    int ans = inf;
    while(!bfs.empty()){
        int u = bfs.front();
        dbg(u);
        bfs.pop();
        for(int nb : adj[u]){
            dbg(nb);
            if(dist[nb] == inf){
                dist[nb] = dist[u] + 1;
                bfs.push(nb);
            }
            else if(dist[nb] >= dist[u]){
                dbg("Cycle found");
                dbg(u);
                dbg(nb);
                ans = min(ans, dist[u] + dist[nb] + 1);
            }
        }
    }
    dbg(dist);
    return ans;
}

void solve(int num_tc) {
    int n, m;
    cin >> n >> m;
    adj.resize(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a - 1].push_back(b - 1);
        adj[b - 1].push_back(a - 1);
    }
    

    int mindist = inf;
    for (int start = 0; start < n; start++) {
        int x = min_cycle(start);
        mindist = min(mindist, x);
    }
    cout << (mindist == inf ? -1 : mindist) << endll;
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
