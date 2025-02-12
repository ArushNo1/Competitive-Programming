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

int x, y, m, k;
int dist;

map<ii, int> vis;

void dfs(int a, int b, int d){
    if(d > k) {
        return;
    }
    if(vis[{a, b}]) {
        return;
    }
    vis[{a, b}] = true;
    if(dist == 0) {
        return;
    }
    dist = min(dist, abs(a + b - m));
    if(a != 0) dfs(0, b, d + 1);
    if(a != x) dfs(x, b, d + 1);
    if(b != 0) dfs(a, 0, d + 1);
    if(b != y) dfs(a, y, d + 1);
    int pour = min(a, y - b);
    if(pour != 0) dfs(a - pour, b + pour, d + 1);
    pour = min(x - a, b);
    if(pour != 0) dfs(a + pour, b - pour, d + 1);
}

struct node{
    int a, b, d;
};

void solve(int num_tc)
{
    cin >> x >> y >> k >> m;
    dist = m;
    dfs(0, 0, 0);

    vector<vector<bool>> vis(x + 1, vector<bool>(y + 1, false));
    queue<node> bfs;
    bfs.push({0, 0, 0});
    while(!bfs.empty()){
        auto [a, b, d] = bfs.front();
        bfs.pop();
        if(dist == 0) break;
        if(d > k) continue;
        if(vis[a][b]) continue;
        vis[a][b] = true;
        dist = min(dist, abs(a + b - m));
        if(a != 0) bfs.push({0, b, d + 1});
        if(a != x) bfs.push({x, b, d + 1});
        if(b != 0) bfs.push({a, 0, d + 1});
        if(b != y) bfs.push({a, y, d + 1});
        int pour = min(a, y - b);
        if(pour != 0) bfs.push({a - pour, b + pour, d + 1});
        pour = min(x - a, b);
        if(pour != 0) bfs.push({a + pour, b - pour, d + 1});
    }
    cout << dist << endll;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);  
    open("pails");
    ll T = 1;
    //cin >> T;
    for(ll t = 0; t < T; t++){
        solve(t+1);
    }
}
