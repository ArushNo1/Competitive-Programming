/*
  Author: taha-r and Arushno1
  Cereal Killers
*/

#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

typedef long long ll;
typedef long double ld;
typedef tree<ll,null_type,less<ll>,rb_tree_tag,
tree_order_statistics_node_update> indexed_set;

#define endll '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define sz(a) ll((a).size())
#define MOD ll(1e9+7)
#define INF ll(2e63-1)

inline void open(const char *fin, const char *fout)
{
    freopen(fin, "r", stdin);
    freopen(fout, "w", stdout);
}

#define dbg(x) cerr << __LINE__ << ": " << #x << "=" << x << endl;

template <typename T> ostream &operator<<(ostream &os, vector<T> &arr) {
	os << "[";
	for (T &x : arr) {
		os << x << " ";
	}
	os << "]";
	return os;
}

template <typename T, typename U>
ostream &operator<<(ostream &os, pair<T, U> &x) {
	os << "(" << x.first << ", " << x.second << ")";
	return os;
}

template <typename T, typename U>
ostream &operator<<(ostream &os, vector<pair<T, U>> &arr) {
	os << "{\n";
	for (const pair<T, U> &x : arr) {
		os << "    (" << x.first << ", " << x.second << ")\n";
	}
	os << "}";
return os;
}

template <typename T> void prll(vector<vector<T>> &mat, ostream &os = cerr) {
	for (vector<T> &arr : mat) {
		for (T &x : arr) {
		os << x << " ";
		}
		os << endll;
	}
}

template <typename T> void prll(vector<T> &arr, ostream &os = cerr) {
	for (T &x : arr) {
		os << x << " ";
	}
	os << endll;
}

namespace math {
// time = O(log(N))
ll binExp(ll a, ll b) {
  if (b == 0)
    return 1;

  ll res = binExp(a, b / 2) % MOD;
  if (b & 1) {
    return (a * ((res * res) % MOD)) % MOD;
  } else
    return (res * res) % MOD;
}

// Time = O(log(N))
ll invMod(ll x) {
  if (x <= 1) {
    return x;
  }
  return MOD - MOD / x * invMod(MOD % x) % MOD;
}

void sieve(vector<bool>& is_prime, ll n)
{
    is_prime[0] = is_prime[1] = false;
    for (ll i = 2; i <= n; i++) {
        if (is_prime[i] && (ll)i * i <= n) {
            for (ll j = i * i; j <= n; j += i)
                is_prime[j] = false;
        }
    }
}

bool isPrime(ll x) {
    for (ll d = 2; d * d <= x; d++) {
        if (x % d == 0)
            return false;
    }
    return x >= 2;
}

vector<ll> factors(ll n, vector<ll> &primes) {
    vector<ll> factorization;
    for (ll d : primes) {
        if (d * d > n)
            break;
        while (n % d == 0) {
            factorization.push_back(d);
            n /= d;
        }
    }
    if (n > 1)
        factorization.push_back(n);
    return factorization;
}

}; // namespace math

namespace ds {
struct DSU {
  	vector<ll> e;
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

class SegTree {
public:
	typedef ll T;
	static constexpr T unit = 0;

  	// (any associative fn)
  	T f(T a, T b) { return a+b; }

  	vector<T> s;
  	ll n;

  	SegTree(ll n = 0, T def = unit) : s(2 * n, def), n(n) {}

  	void update(ll pos, T val) {
    	for (s[pos += n] = val; pos /= 2;)
      		s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
  	}

  	void build(vector<T> &v) {
    	for (ll i = 0; i < (ll)v.size(); i++)
      		update(i, v[i]);
  	}

  	T query(ll b, ll e) { // query [b, e)
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

template <typename T> class SparseTable {
private:

	int n, log2dist;
	vector<vector<T>> st;

public:

	SparseTable(const vector<T> &v) {
		n = (int)v.size();
		log2dist = 1 + (int)log2(n);
		st.resize(log2dist);
		st[0] = v;
		for (int i = 1; i < log2dist; i++) {
			st[i].resize(n - (1 << i) + 1);
			for (int j = 0; j + (1 << i) <= n; j++) {
				st[i][j] = min(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
			}
		}
	}

	/** @return minimum on the range [l, r] */
	T query(int l, int r) {
		int i = (int)log2(r - l + 1);
		return min(st[i][l], st[i][r - (1 << i) + 1]);
	}
};

class LCA {
private:
	const int n;
	const vector<vector<int>> &adj;
	SparseTable<pair<int, int>> rmq;
	vector<int> tin, et, dep;
	int timer = 0;

	/** prepares tin, et, dep arrays */
	void dfs(int u, int p) {
		tin[u] = timer;
		et[timer++] = u;
		for (int v : adj[u]) {
			if (v == p) { continue; }
			dep[v] = dep[u] + 1;
			dfs(v, u);
			et[timer++] = u;
		}
	}

public:
	// make sure the adjacency list is 0 indexed
	LCA(vector<vector<int>> &_adj)
	    : n((int)_adj.size()), adj(_adj), tin(n), et(2 * n), dep(n),
	      rmq(vector<pair<int, int>>(1)) {
		dfs(0, -1);
		vector<pair<int, int>> arr(2 * n);
		for (int i = 0; i < 2 * n; i++) { arr[i] = {dep[et[i]], et[i]}; }
		rmq = SparseTable<pair<int, int>>(arr);
	}

	/** @return LCA of nodes a and b */
	int query(int a, int b) {
		if (tin[a] > tin[b]) { swap(a, b); }
		return rmq.query(tin[a], tin[b]).second;
	}
};
} // namespace ds

void solve(int num_tc)
{
	int n, m;
	cin >> n >> m;
	int good = 0, bad = 0;
	for(int r = 0; r < n; r++){
		for(int c = 0; c < m; c++){
			char x = ((r + c) & 1) + '0';
			char g;
			cin >> g;
			
			if(g == x){
				++good;
			}
			else{
				++bad;
			}
		}
	}
	cout << min(good, bad) << endll;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);  

    ll T = 1;
    cin >> T;
    for(ll t = 0; t < T; t++)
    {
        solve(t+1);
    }
}