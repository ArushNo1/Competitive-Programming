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

struct edge{
    int a, b;
    ll w;
    bool operator < (const edge& other) const {
        return w > other.w;
    }
    friend ostream& operator<< (ostream& os, const edge& e){
        os << e.a << " " << e.b << " " << e.w;
        return os;
    }
};
struct query{
    ll rel;
    int vid;
    int ind;
    bool operator < (const query& other) const {
        return rel > other.rel;
    }
};

void solve(int num_tc)
{
    int n, q;
    cin >> n >> q;
    vector<edge> edges(n - 1);
    for(int i = 0; i < n - 1; i++){
        int a, b;
        ll c;
        cin >> a >> b >> c;
        edges[i] = {a - 1, b - 1, c};
    }
    sort(all(edges));
    dbg(edges);
    vector<int> ans(q);
    vector<query> queries(q);
    for(int i = 0; i < q; i++){
        cin >> queries[i].rel >> queries[i].vid;
        queries[i].ind = i;
        queries[i].vid--;
    }
    sort(all(queries));
    int ep = 0;
    DSU dsu(n);
    for(int i = 0; i < q; i++){
        while(ep < n - 1 && edges[ep].w >= queries[i].rel){
            dsu.unite(edges[ep].a, edges[ep].b);
            ep++;
        }
        ans[queries[i].ind] = dsu.size(queries[i].vid);
    }
    for(int i = 0; i < q; i++){
        cout << ans[i] - 1 << endll;
    }
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);  
    dbg("turn off debugging");
    open("mootube");
    ll T = 1;
    //cin >> T;
    for(ll t = 0; t < T; t++){
        solve(t+1);
    }
}
