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
    int n, s1, s2;
    cin >> n >> s1 >> s2;
    s1--; s2--;
    //FFFGGG
    int m1;
    cin >> m1;
    vvi adj1(n);
    for(int i = 0; i < m1; i++){
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj1[u].push_back(v);
        adj1[v].push_back(u);
    }
    int m2;
    cin >> m2;
    vvi adj2(n);
    for(int i = 0; i < m2; i++){
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj2[u].push_back(v);
        adj2[v].push_back(u);
    }

    vector<vector<bool>> vis(n, vector<bool>(n));
    vector<vector<int>> dist(n, vector<int>(n, 1e9));
    //vis[f][g]
    priority_queue<ii, vector<ii>, greater<ii>> dij;
    for(int i = 0; i < n; i++){
        dij.push({i, i});
        dist[i][i] = 0;
    }

    while(!dij.empty()){
        int u = dij.top().first;
        int v = dij.top().second;
        dij.pop();
        if(vis[u][v]) continue;
        vis[u][v] = true;
        if(u == s1 && v == s2){
            break;
        }
        for(int nb1 : adj1[u]){
            for(int nb2 : adj2[v]){
                if(vis[nb1][nb2]) continue;
                dist[nb1][nb2] = min(dist[nb1][nb2], dist[u][v] + abs(nb1 - nb2));
                dij.push({nb1, nb2});
            }
        }
    }
    cout << (dist[s1][s2] == 1e9 ? -1 : dist[s1][s2]) << endll;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);  
    dbg("turn off debugging");
    ll T = 1;
    cin >> T;
    for(ll t = 0; t < T; t++){
        solve(t+1);
    }
}
