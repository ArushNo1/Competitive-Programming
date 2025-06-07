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

vvi adj;

vector<bool> visited;
vi bracelet;
bool done = false;

void dfs(int node){
    dbg(node);
    dbg(bracelet);
    if(visited[node]){
        if((bracelet.size() == visited.size()) && bracelet[0] == node){
            done = true;
        }
        return;
    }
    visited[node] = true;
    bracelet.push_back(node);
    dbg(adj[node]);
    for(int i = 0; i < 2; i++){
        int next = adj[node][i];
        dfs(next);
        if(done) return;
    }
    bracelet.pop_back();
    visited[node] = false;
}

void solve(int num_tc)
{
    int n;
    cin >> n;
    adj.resize(n);
    visited.resize(n, false);
    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        a--; b--;
        adj[i].push_back(a);
        adj[i].push_back(b);
    }
    dfs(0);
    if(!done){
        cout << -1 << endll;
        return;
    }
    for(int i = 0; i < bracelet.size(); i++){
        cout << bracelet[i] + 1 << " ";
    }
    cout << endll;
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
