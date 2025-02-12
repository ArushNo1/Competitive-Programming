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

vector<int> CC;
vector<bool> visited;
vector<vector<int>> adj;
void dfs(int node){
    if(visited[node]) return;
    visited[node] = true;
    CC.push_back(node);
    for(int v : adj[node]){
        dfs(v);
    }
}

ll result(vector<int>& a, vector<int>& b){
    ll best = INF;
    for(int x : b){
        auto it = lower_bound(all(a), x);
        if(it != a.end()){
            best = min(best, (ll)(abs(*it - x)));
        }
        if(it != a.begin()){
            it--;
            best = min(best, (ll)(abs(*it - x)));
        }
    }
    return best * best;
}

void solve(int num_tc)
{
    adj.clear();
    visited.clear();
    CC.clear();
    int n, m;
    cin >> n >> m;
    adj.resize(n);
    visited.resize(n, false);
    for(int i= 0 ;i < m; i++){
        int a, b;
        cin >> a >> b;
        adj[a - 1].push_back(b - 1);
        adj[b - 1].push_back(a - 1);
    }   
    dbg(adj);
    vector<vector<int>> CCs;
    vector<int> s;
    vector<int> d;
    for(int i = 0; i < n; i++){
        if(!visited[i]){
            dfs(i);
            dbg(i);
            dbg(CC);
            sort(all(CC));
            if(CC[0] == 0){
                s = CC;
            }
            else if(CC.back() == n - 1){
                d = CC;
            }
            else CCs.push_back(CC);
            CC.clear();
        }
        //cerr << i << endl;
    }
    dbg(s);
    if(s.back() == (n - 1)){
        cout << 0 << endll;
        return;
    }
    ll dist = result(s, d);
    for(int i = 0; i < CCs.size(); i++){
        //cerr << "2" << i << endll;
        dist = min(dist, result(s, CCs[i]) + result(d, CCs[i]));
        if(dist == 1) break;
    }
    cout << dist << endll;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);  
    ll T = 1;
    cin >> T;
    for(ll t = 0; t < T; t++){
        solve(t+1);
    }
}
