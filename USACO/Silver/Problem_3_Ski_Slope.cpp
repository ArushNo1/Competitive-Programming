#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops") 
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;


typedef long long ll;
typedef pair<ll, ll> pll;
typedef tree<pll,null_type,greater<pll>,rb_tree_tag,
tree_order_statistics_node_update> indexed_set;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;

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


vector<map<ll, ll>> ans(11, map<ll, ll>());
indexed_set ds;
ll sume;
//{diff, enjoyment}
vector<vector<pair<ll, pll>>> adj;
int c;


//parent adds, children subtract
void dfs(ll node, ll d, ll e){
    //ans[c][d] = max(ans[c][d], e);
    //use the above calculation with d as the c'th largest element
    ll mind = 0;
    if(c < ds.size()){
        mind = ds.find_by_order(c)->first;
    }
    ans[c][mind] = max(ans[c][mind], sume);
    for(auto& p : adj[node]){
        ll nb = p.first;
        ll nbd = p.second.first;
        ll nbe = p.second.second;
        sume += nbe;
        ds.insert({nbd, nb});
        dfs(nb, nbd, nbe);
    }

    sume -= e;
    auto it = ds.find({d, node});
    if (it != ds.end()) ds.erase(it);
}

void solve(int num_tc)
{
    int n;
    cin >> n;
    adj.resize(n);
    for(int i = 0; i < n - 1; i++){
        int u, a, b;
        cin >> u >> a >> b;
        u--;
        adj[u].push_back({i + 1, {a, b}});
    }
    dbg(adj);
    for(c = 0; c <= 10; c++){
        sume = 0;
        ds.clear();
        ds.insert({0, 0});
        dfs(0, 0, 0);
        for(auto it = ans[c].begin(); it != ans[c].end(); it++){
            if(it == ans[c].begin()) continue;
            it->second = max(it->second, prev(it)->second);
        }
    }
    dbg(ans);
    int m;
    cin >> m;
    for(int i = 0; i < m; i++){
        int k, c2;
        cin >> k >> c2;
        dbg(k);
        dbg(c2);
        auto it = ans[c2].upper_bound(k);
        if(it == ans[c2].begin()){
            cout << 0 << endll;
        } else {
            it--;
            cout << it->second << endll;
        }
    }
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
