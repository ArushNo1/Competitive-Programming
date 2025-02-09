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
#define maxeq(a, b) a = max<decltype(a)>(a, b)
#define mineq(a, b) a = min<decltype(a)>(a, b)

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
template <typename T, typename U>
inline void fillv(vector<pair<T, U>>& v, int n, bool inv = false){
	if(inv){
		for(int i = 0 ; i < n; ++i){
			cin >> v[i].second >> v[i].first;
		}
		return;
	}
	for (int i = 0; i < n; ++i) {
        cin >> v[i].first >> v[i].second;
    }
	return;
}

inline void open(string name){
    freopen((name + ".in").c_str(), "r", stdin);
	freopen((name + ".out").c_str(), "w", stdout);
}

/**
 * @brief A Segment Tree implementation for range queries and point updates
 *
 * This class implements a segment tree data structure that supports:
 * - Point updates in O(log n) time
 * - Range queries in O(log n) time
 * - Construction in O(n) time
 * The tree maintains associative operations (like sum, min, max) over ranges
 */
struct node{
    ll seg;
    ll pref;
    ll suf;
    ll sum;
    node(){
        seg = pref = suf = sum = 0;
    }
    node(ll seg, ll pref, ll suf, ll sum) : seg(seg), pref(pref), suf(suf), sum(sum) {}
    node(ll sum) {
        this->sum = sum;
        seg = pref = suf = max(0ll, sum);
    }
    node operator+(const node &rhs) const {
        node res;
        res.sum = sum + rhs.sum;
        res.pref = max(pref, sum + rhs.pref);
        res.suf = max(rhs.suf, suf + rhs.sum);
        res.seg = max({seg, rhs.seg, suf + rhs.pref});
        return res;
    }
};
static const node unit = {0, 0, 0, 0};
class SegTree {
    public:
      
      typedef node T;                // Type alias for the tree's value type
      //static const T unit(0,0,0,0); // Identity element for the operation
  
      /**
       * @brief Combines two values using the tree's operation
       * @param a First value
       * @param b Second value
       * @return Result of combining a and b
       */
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


//comment to enable debugging
#define dbg(x)

#ifndef dbg
#define dbg(x) cerr << __LINE__ << ": " << #x << "=" << x << endl;
//edit for specific DS
#include "cp-templates/Debugging/alldebug.h"
#endif

void solve(int num_tc)
{
    int n, q;
    cin >> n >> q;
    vector<node> arr(n);
    for(int i = 0; i < n; i++){
        int t;
        cin >> t;
        arr[i] = node(t);
    }
    SegTree st(n);
    st.build(arr);
    cout << st.query(0, n).seg << endll;
    for(int i = 0; i < q; i++){
        int a, b;
        cin >> a >> b;
        st.update(a, node(b));
        cout << st.query(0, n).seg << endll;
    }
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);  

    ll T = 1;
    //cin >> T;
    for(ll t = 0; t < T; t++){
        solve(t+1);
    }
}
