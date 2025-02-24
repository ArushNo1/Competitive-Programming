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

void solve(int num_tc)
{
    int n, m;
    cin >> n >> m;
    vi energy(n);
    fillv(energy, n);
    vi cost(n);
    vvi adj(n);
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
        cost[u] += energy[v];
        cost[v] += energy[u];
    }
    dbg(cost);
    set<int> removed;
    priority_queue<ii, vector<ii>> pq;
    for(int i = 0; i < n; i++){
        pq.push({energy[i], i});
    }
    ll spent = 0;
    while(!pq.empty() && removed.size() < n - 1){
        ii t = pq.top();
        int u = t.second;
        dbg(t);
        pq.pop();
        if(removed.find(u) != removed.end()) continue;
        removed.insert(u);
        dbg(removed);
        for(auto v : adj[u]){
            if(removed.find(v) != removed.end()) continue;
            cost[v] -= energy[u];
            dbg(v);
            dbg(cost[v]);
        }
        spent += cost[u];
    }
    cout << spent << endll;
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
