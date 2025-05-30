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

int ccsize = 0;

vector<set<int>> adj;
set<int> unvisited;

void dfs(int node) {
    ccsize++;
    vector<int> to_visit;
    for(int nb : unvisited) {
        if(!adj[node].count(nb)) {
            to_visit.push_back(nb);
        }
    }
    for(int nb : to_visit) {
        unvisited.erase(nb);
    }
    for(int nb : to_visit) {
        dfs(nb);
    }
}

void solve(int num_tc)
{
    int n, m;
    cin >> n >> m;
    adj.assign(n, set<int>());
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        a--; b--;
        adj[a].insert(b);
        adj[b].insert(a);
    }
    for(int i = 0; i < n; i++) {
        unvisited.insert(i);
    }
    vector<int> ccs;
    int components = 0;
    while(!unvisited.empty()) {
        int node = *unvisited.begin();
        ccsize = 0;
        unvisited.erase(node);
        dfs(node);
        components++;
        ccs.push_back(ccsize);
    }
    sort(all(ccs));
    cout << components << endll;
    for(int i = 0; i < components; i++) {
        cout << ccs[i] << " ";
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
