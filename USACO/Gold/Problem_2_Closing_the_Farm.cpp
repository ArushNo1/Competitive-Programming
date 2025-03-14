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

struct DSU {
    vector<ll> color;
  DSU(ll N) {
      color = vector<ll>(N, -1); 
  }
    void init(ll N) { 
      color = vector<ll>(N, -1); 
  }
    ll get(ll x) { 
      return color[x] < 0 ? x : color[x] = get(color[x]); 
  }
    bool sameSet(ll a, ll b) {
      return get(a) == get(b); 
  }
    ll size(ll x) {
      return -color[get(x)]; 
  }
    bool unite(ll x, ll y) { // union by size
      x = get(x), y = get(y);
      if (x == y)
        return 0;
      if (color[x] > color[y])
        swap(x, y);
  
      color[x] += color[y];
      color[y] = x;
      return 1;
    }
};
void solve(int num_tc)
{
    int n, m;
    cin >> n >> m;
    vvi adj(n);
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vi closes;
    for(int i = 0; i < n; i++){
        int c;
        cin >> c;
        c--;
        closes.push_back(c);
    }
    reverse(all(closes));
    dbg(closes);
    dbg(adj);
    int numcomps = 0;
    vector<string> result;
    DSU dsu(n);
    set<int> open;
    for(int i = 0; i < n; i++){
        numcomps++;
        int cur = closes[i];
        open.insert(cur);
        dbg(cur);
        dbg(numcomps);
        if(numcomps == 1){
            result.push_back("YES");
            continue;
        }
        dbg(adj[cur]);
        for(int j : adj[cur]){
            if(!open.count(j)) continue;
            if(!dsu.sameSet(cur, j)){
                dbg(j);
                dsu.unite(cur, j);
                numcomps--;
                dbg(numcomps);
            }
            if(numcomps == 1){
                result.push_back("YES");
                break;
            }
        }
        if(numcomps > 1){
            result.push_back("NO");
        }
    }
    //result.push_back(dsu.size(0) == n ? "YES" : "NO");
    reverse(all(result));
    for(string s : result){
        cout << s << endll;
    }
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);  
    dbg("turn off debugging");
    open("closing");
    ll T = 1;
    //cin >> T;
    for(ll t = 0; t < T; t++){
        solve(t+1);
    }
}
