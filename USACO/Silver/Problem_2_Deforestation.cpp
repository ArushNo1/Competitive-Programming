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

class SegTree {
    public:
      typedef int T;                // Type alias for the tree's value type
      static constexpr T unit = 0; // Identity element for the operation  
      T f(T a, T b) { return a + b; }
      vector<T> s; // Internal tree storage
      ll n;        // Size of the original array
      SegTree(ll n = 0, T def = unit) : s(2 * n, def), n(n) {}
      void update(ll pos, T val) {
          for (s[pos += n] = val; pos /= 2;)
              s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
      }
      void build(vector<T> &v) {
          for (ll i = 0; i < (ll)v.size(); i++)
              update(i, v[i]);
      }
      T query(ll b, ll e) {
          T ra = unit, rb = unit;
          for (b += n, e += n; b < e; b /= 2, e /= 2) {
              if (b % 2)
                  ra = f(ra, s[b++]);
              if (e % 2)
                  rb = f(s[--e], rb);
          }
          return f(ra, rb);
      }
  };
struct interval{
    int l, r, t;
    friend ostream& operator<< (ostream& os, const interval& x){
        return os << "[" << x.l << ", " << x.r << "]: " << x.t << endll;
    }
};
void solve(int num_tc)
{
    int n, k;
    cin >> n >> k;
    vi trees(n);
    fillv(trees, n);
    sort(all(trees));
    vector<interval> intervals(k);
    int bigtree = 0;
    for(int i = 0; i < k; i++){
        int l, r, t;
        cin >> l >> r >> t;
        intervals[i].t = t;
        intervals[i].l = lower_bound(all(trees), l) - trees.begin();
        intervals[i].r = min(n - 1, (int)(upper_bound(all(trees), r) - trees.begin() - 1));
        bigtree = max(bigtree, intervals[i].r);
    }
    bigtree++;
    sort(all(intervals), [](interval a, interval b){
        if(a.r != b.r) return a.r < b.r;
        if(a.l != b.l) return a.l < b.l;
        return a.t > b.t;
    });
    SegTree tpref(n);
    vector<int> placed(n, 0);
    tpref.build(placed);
    for(int i = 0; i < k; i++){
        interval cur = intervals[i];
        int def = tpref.query(cur.l, cur.r + 1) - cur.t;
        if(def >= 0) continue;
        for(int j = cur.r; j >= cur.l; j--){
            if(placed[j]) continue;
            tpref.update(j, 1);
            placed[j] = 1;
            def++;
            if(def == 0) break;
        }
    }
    cout << n - tpref.query(0, n) << endll;
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
