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



class SegTree {
    public:
    struct node {
        int firstpos, fpindex;
        int lastneg, lnindex;
        node() : firstpos(inf), fpindex(inf), lastneg(-inf), lnindex(-1) {}
        node (int ind, int val) : firstpos(inf), fpindex(inf), lastneg(-inf), lnindex(-1) {
            if(val > 0){
                firstpos = val;
                fpindex = ind;
            } else {
                lastneg = val;
                lnindex = ind;
            }
        }
        node operator+(const node &other) const {
            node res;
            if (fpindex < other.fpindex) {
                res.firstpos = firstpos;
                res.fpindex = fpindex;
            } else {
                res.firstpos = other.firstpos;
                res.fpindex = other.fpindex;
            }
    
            if (lnindex > other.lnindex) {
                res.lastneg = lastneg;
                res.lnindex = lnindex;
            } else {
                res.lastneg = other.lastneg;
                res.lnindex = other.lnindex;
            }
    
            return res;
        }
        friend ostream& operator<<(ostream& os, const node& n) {
            return os << "pos: " << n.firstpos << "@" << n.fpindex << ", neg: " << n.lastneg << "@" << n.lnindex;
        }
    };
    
      typedef node T;                // Type alias for the tree's value type
      static T unit; // Identity element for the operation
  
      T f(T a, T b) { return a + b; }
  
      vector<T> s; // Internal tree storage
      ll n;        // Size of the original array
  
      /**
       * @brief Constructs a segment tree
       * @param n Size of the array
       * @param def Default value for initialization (default = unit)
       */
      SegTree(ll n = 0, T def = unit) : s(2 * n, def), n(n) {}
  
      /**
       * @brief Updates a single position in the tree
       * @param pos Position to update (0-based)
       * @param val New value
       * Time complexity: O(log n)
       */
      void update(ll pos, T val) {
          for (s[pos += n] = val; pos /= 2;)
              s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
      }
  
      /**
       * @brief Builds the tree from an array
       * @param v Input array
       * Time complexity: O(n)
       */
      void build(vector<T> &v) {
          for (ll i = 0; i < (ll)v.size(); i++)
              update(i, v[i]);
      }
  
      /**
       * @brief Queries a range [b, e)
       * @param b Beginning of range (inclusive)
       * @param e End of range (exclusive)
       * @return Result of combining all elements in the range
       * Time complexity: O(log n)
       */
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
  SegTree::T SegTree::unit = SegTree::node();


struct state{
    ll money;
    int l, r;
    bool done = false;
    friend ostream& operator<<(ostream& os, const state& s){
        return os << "[" << s.l << ", " << s.r << ", " << s.money << "] ";
    }
};
state compare(state a, state b){
    bool afail = a.l == inf || a.r < 0 || a.l > a.r;
    bool bfail = b.l == inf || b.r < 0 || b.l > b.r;
    if(afail && bfail){
        return {inf, -1, -1};
    }
    if(afail){
        return b;
    }
    if(bfail){
        return a;
    }
    if(a.money > b.money){
        return a;
    }
    return b;
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
    int n;
    cin >> n;
    vector<SegTree::node> a(n);
    vi vals(n);
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        a[i] = SegTree::node(i, x);
        vals[i] = x;
    }
    if(n == 1){
        cout << abs(vals[0]) << endll;
        return;
    }
    SegTree seg(n);
    seg.build(a);
    vector<vector<state>> dp(n + 1, vector<state>(2, {0, 0, n}));
    for(int i = 1; i <= n; i++){
        dbg(i);
        //take the first positive in the thing
        SegTree::node previousfrompositivenode = seg.query(dp[i - 1][0].l, dp[i - 1][0].r);
        dbg(dp[i - 1][0]);
        dbg(previousfrompositivenode);
        SegTree::node previousfromnegativenode = seg.query(dp[i - 1][1].l, dp[i - 1][1].r);
        dbg(dp[i - 1][1]);
        dbg(previousfromnegativenode);
        state iffrompositivenode;
        if(dp[i - 1][0].done){
            iffrompositivenode = dp[i - 1][0];
        }
        else{
            iffrompositivenode.money = dp[i - 1][0].money + previousfrompositivenode.firstpos;
            iffrompositivenode.l = previousfrompositivenode.fpindex + 1;
            iffrompositivenode.r = dp[i - 1][0].r;   
        }
        dbg(iffrompositivenode);
        state iffromnegativenode;
        if(dp[i - 1][1].done){
            iffromnegativenode = dp[i - 1][1];
        } else {
            iffromnegativenode.money = dp[i - 1][1].money + previousfromnegativenode.firstpos;
            iffromnegativenode.l = previousfromnegativenode.fpindex + 1;
            iffromnegativenode.r = dp[i - 1][1].r;
        }
        dbg(iffromnegativenode);
        dp[i][0] =  compare(iffrompositivenode, iffromnegativenode);
        dbg(dp[i][0]);
        if(dp[i][0].l == dp[i][0].r){
            dp[i][0].done = true;
        }
        //take the last negative in the thing
        state frompos2;
        if(dp[i - 1][0].done){
            frompos2 = dp[i - 1][0];
        }
        else{
            frompos2.money = dp[i - 1][0].money + abs(previousfrompositivenode.lastneg);
            frompos2.l = dp[i - 1][0].l;
            frompos2.r = previousfrompositivenode.lnindex;    
        }
        dbg(frompos2);
        state fromneg2;
        if(dp[i - 1][1].done){
            fromneg2 = dp[i - 1][1];
        }
        else{
            fromneg2.money = dp[i - 1][1].money + abs(previousfromnegativenode.lastneg);
            fromneg2.l = dp[i - 1][1].l;
            fromneg2.r = previousfromnegativenode.lnindex;
        }
        dp[i][1] = compare(frompos2, fromneg2);
        if(dp[i][1].l == dp[i][1].r){
            dp[i][1].done = true;
        }
        dbg(fromneg2);
        dbg(dp[i][1]);
        //if(i == 3) break;
    }

    cout << compare(dp[n][0], dp[n][1]).money << endll;
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
