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

struct node{
    int maxl, len;
    int p1, p0;
    int s1, s0;
    node(){
        p1 = p0 = s1 = s0 = maxl = len = 0;
    }
    node(char c){
        maxl = 1;
        len = 1;
        p1 = p0 = s1 = s0 = 0;
        if(c == '1'){
            p1++; s1++;
        }
        else{
            p0++; s0++;
        }
    }
    friend node operator+(node& a, node& b){
        node result;
        result.len = a.len + b.len;
        result.p0 = a.p0 + (a.p0 == a.len? b.p0 : 0);
        result.p1 = a.p1 + (a.p1 == a.len? b.p1 : 0);
        result.s0 = b.s0 + (b.s0 == b.len? a.s0 : 0);
        result.s1 = b.s1 + (b.s1 == b.len? a.s1 : 0);
        result.maxl = max(a.maxl, b.maxl);
        result.maxl = max(result.maxl, 
            max(a.s0 + b.p0, a.s1 + b.p1)
        );      
        return result;
    }
};

node unit;

class SegTree {
    public:
      typedef node T;                // Type alias for the tree's value type
  
      /**
       * @brief Combines two values using the tree's operation
       * @return Result of combining a and b
       */
      T f(T a, T b) { return a + b; }
  
      vector<T> s;
      ll n;        
  
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
       * @return Result of combining all elements in the range
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

void solve(int num_tc)
{
    string s;
    cin >> s;
    int n = s.size();
    vector<node> nodes(n);
    for(int i = 0; i < n; i++){
        nodes[i] = node(s[i]);
    }
    SegTree st(n);
    st.build(nodes);
    int q;
    cin >> q;
    for(int i = 0; i < q; i++){
        int x;
        cin >> x;
        x--;
        s[x] = '0' + '1' - s[x];
        st.update(x, node(s[x]));
        cout << st.query(0, n).maxl << " ";
    }
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
