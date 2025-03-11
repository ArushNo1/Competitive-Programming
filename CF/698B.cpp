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
    vector<ll> e;
  DSU(ll N) {
      e = vector<ll>(N, -1); 
  }
    void init(ll N) { 
      e = vector<ll>(N, -1); 
  }
    ll get(ll x) { 
      return e[x] < 0 ? x : e[x] = get(e[x]); 
  }
    bool sameSet(ll a, ll b) {
      return get(a) == get(b); 
  }
    ll size(ll x) {
      return -e[get(x)]; 
  }
    bool unite(ll x, ll y) { // union by size
      x = get(x), y = get(y);
      if (x == y)
        return 0;
      if (e[x] > e[y])
        swap(x, y);
  
      e[x] += e[y];
      e[y] = x;
      return 1;
    }
};

vi p;
set<int> visited;
int root = -1;
int numchanges = 0;

void dfs(int node){
    if(visited.count(node)){
        return;
    }
}

void solve(int num_tc)
{
    int n;
    cin >> n;
    p.resize(n);
    for(int i= 0; i < n; i++){
        cin >> p[i];
        p[i]--;
        if(p[i] == i){
            root = i;
        }
    }
    DSU dsu(n);
    vi needsrooting;
    for(int i = 0; i < n; i++){
        if(i == root){
            continue;
        }
        bool res = dsu.unite(i, p[i]);
        if(res){
            continue;
        }
        else{
            if(root == -1){
                needsrooting.push_back(i);
            }
            else{
                p[i] = root;
                numchanges++;
            }
        }
    }
    for(int i = 0; i < n; i++){
        if(dsu.size(i) == 1){
            root = i;
            for(int j : needsrooting){
                p[j] = root;
                numchanges++;
            }
            break;
        }
    }
    if(root == -1){
        root = needsrooting[0];
        for(int j : needsrooting){
            p[j] = root;
            numchanges++;
        }
    }
    cout << numchanges << endll;
    for(int i : p){
        cout << i + 1 << " ";
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


//2 3 5 4 1 6 6 7