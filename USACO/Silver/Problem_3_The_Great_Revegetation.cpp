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

//comment to enable debugging
#define dbg(x)

#ifndef dbg
#define dbg(x) cerr << __LINE__ << ": " << #x << "=" << x << endl;
//edit for specific DS
#include "cp-templates/Debugging/alldebug.h"
#endif

vector<vector<pair<int, char>>> adj;
vector<int> color;
bool fail = false;

void dfs(int node, int c){
    if(fail) return;
    if(color[node] != -1){
        if(color[node] != c){
            fail = true;
        }
        return;
    }
    color[node] = c;
    for(auto& [nei, col] : adj[node]){
        if(col == 'S'){
            dfs(nei, c);
        }else{
            dfs(nei, 1-c);
        }
        if(fail) return;
    }
}

void solve(int num_tc)
{
    int n, m;
    cin >> n >> m;
    adj.resize(n);
    color.assign(n, -1);
    for(int i = 0; i < m; i++){
        char c;
        cin >> c;
        int a, b;
        cin >> a >> b;
        a--; b--;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }    
    int components = 0;
    for(int i = 0; i < n; i++){
        if(color[i] == -1){
            dfs(i, 0);
            components++;
            if(fail){
                cout << 0 << endll;
                return;
            }
        }
    }
    cout << 1;
    for(int i = 0; i < components; i++){
        cout << 0;
    }
    cout << endll;
}

inline void open(string name){
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
}    

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);  
    //open("revegetate");
    ll T = 1;
    //cin >> T;
    for(ll t = 0; t < T; t++){
        solve(t+1);
    }
}
