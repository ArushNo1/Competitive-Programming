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
typedef long long ll;
typedef vector<ll> vll;
typedef pair<ll, ll> pll;

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

struct solution{
map<int, int> path;
vvi adj;
int entrynode = -1;
int cyclesize = 0;
int adepth = 0;

void dfs1(int node, int par, int depth){
    if(path.count(node)){
        entrynode = node;
        adepth = depth;
        cyclesize = depth - path[node];
        return;
    }
    path[node] = depth;
    for(int child : adj[node]){
        if(child != par){
            dfs1(child, node, depth + 1);
            if(entrynode != -1){
                return;
            }
        }
    }
    if(entrynode != -1){
        return;
    }
    path.erase(node);
}

void bfs(int from, int to){
    vector<bool> visited(adj.size(), false);
    queue<pair<int,int>> q;
    q.push({from, 0});
    visited[from] = true;
    adepth = -1;
    while(!q.empty()){
        auto [node, depth] = q.front();
        q.pop();
        if(node == to){
            adepth = depth;
            return;
        }
        for(int child : adj[node]){
            if(!visited[child]){
                visited[child] = true;
                q.push({child, depth + 1});
            }
        }
    }
}

void solve(int num_tc)
{
    int n, a, b;
    cin >> n >> b >> a;
    a--; b--;
    adj.resize(n);
    for(int i = 0; i < n; i++){
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs1(a, -1, 0);
    dbg(path);
    int timetoescape = adepth - cyclesize;
    dbg(cyclesize);
    dbg(timetoescape);
    adepth = -1;
    dbg(entrynode);
    //adepth is ho long a has to travel to reach the cycle
    bfs(b, entrynode);
    dbg(b);
    dbg(adepth);
    if(adepth <= timetoescape){
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;

}
};

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);  
    dbg("turn off debugging");
    ll T = 1;
    cin >> T;
    for(ll t = 0; t < T; t++){
        solution().solve(t+1);
    }
}
