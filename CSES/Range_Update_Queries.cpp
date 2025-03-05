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

template <class T> class BIT {
	private:
	  int size;
	  vector<T> bit;
	  vector<T> arr;
  
	public:
	  BIT(int size) : size(size), bit(size + 1), arr(size) {}
	  /** Sets the value at index ind to val. */
	  void set(int ind, T val) { add(ind, val - arr[ind]); }
	  /** Adds val to the element at index ind. */
	  void add(int ind, T val) {
		  arr[ind] += val;
		  ind++;
		  for (; ind <= size; ind += ind & -ind) {
			  bit[ind] += val;
		  }
	  }
	  /** @return The sum of all values in [0, ind]. */
	  T pref_sum(int ind) {
		  ind++;
		  T total = 0;
		  for (; ind > 0; ind -= ind & -ind) {
			  total += bit[ind];
		  }
		  return total;
	  }
  };

void solve(int num_tc)
{
    int n, q;
    cin >> n >> q;
    vi arr(n);
    fillv(arr, n);
    BIT<ll> bit(n);
    bit.add(0, arr[0]);
    for(int i = 1; i < n; i++){
        bit.add(i, arr[i] - arr[i - 1]);
    }
    for(int i = 0; i < q; i++){
        int t;
        cin >> t;
        if(t == 2){
            int k;
            cin >> k;
            cout << bit.pref_sum(k - 1) << endll;
        }
        else{
            ll l, r, x;
            cin >> l >> r >> x;
            bit.add(l - 1, x);
            bit.add(r, -x);
        }
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
