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


struct DSU {
  	vector<ll> e;
	DSU(ll N)
	{
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

template<typename T>
T first_true(T lo, T hi, std::function<bool(T)> f) {
	hi++;
	while (lo < hi) {
		T mid = lo + (hi - lo) / 2;
		if (f(mid)) {
			hi = mid;
		} else {
			lo = mid + 1;
		}
	}
	return lo;
}
template<typename T>
T last_true(T lo, T hi, std::function<bool(T)> f) {
    lo--;
    while (lo < hi) {
        T mid = lo + (hi - lo + 1) / 2;
        if (f(mid)) {
            lo = mid;
        } else {
            hi = mid - 1;
        }
    }
    return lo;
}


//comment to enable debugging
#define dbg(x)

#ifndef dbg
#define dbg(x) cerr << __LINE__ << ": " << #x << "=" << x << endl;
//edit for specific DS
#include <alldebug.h>
#endif

struct edge{
    int a, b;
    ll w;
};

void solve(int num_tc)
{
    int n, m;
    cin >> n >> m;
    vi cows(n);
    vi misplaced;
    for(int i= 0; i < n; i++){
        cin >> cows[i];
        cows[i]--;
        if(cows[i] != i){
            misplaced.push_back(i);
        }
    }
    
    vector<edge> edges;
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        ll w;
        cin >> w;
        edges.push_back({a, b, w});
    }
    if(misplaced.size() == 0){
        cout << -1 << endl;
        return;
    }
    sort(all(edges), [](edge a, edge b){
        return a.w > b.w;
    });
    
    DSU dsu(n);

    auto eval = [&](){
        for(int j = 0; j < misplaced.size(); j++){
            if(!dsu.sameSet(misplaced[j], cows[misplaced[j]])){
                return false;
            }
        }
        return true;
    };

    for(int i = 0; i < m; i++){
        dsu.unite(edges[i].a, edges[i].b);
        if(eval()){
            cout << edges[i].w << endl;
            return;
        }
    }
    

    
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);  

    open("wormsort");
    
    ll T = 1;
    //cin >> T;
    for(ll t = 0; t < T; t++){
        solve(t+1);
    }
}
