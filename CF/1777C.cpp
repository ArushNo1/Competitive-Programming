//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops") 
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

vector<ll> get_factors(ll n) {
    vector<ll> ret;
    for (ll i = 1; i * i <= n; i++) {
        if(n % i == 0){
            ret.push_back(i);
            if(i * i != n) ret.push_back(n / i);
        }
    }
    return ret;
}

//comment to enable debugging
#define dbg(x)

#ifndef dbg
#define dbg(x) cerr << __LINE__ << ": " << #x << "=" << x << endl;
//edit for specific DS
#include <alldebug.h>
#endif



void solve(int num_tc)
{
    ll n, m;
    cin >> n >> m;
    dbg(n); dbg(m);

    vector<ll> arr(n);
    vector<vll> factors(n);
    
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    sort(all(arr));
    for(int i = 0; i < n; i++){
        factors[i] = get_factors(arr[i]);
    }

    dbg(factors);
    dbg(arr);

    map<ll, ll> cnt;
    int r = 0;
    ll ans = INF;
    
    dbg(cnt);
    
    for(int l = 0; l < n; l++){
        dbg(l);
        while(r < n && cnt.size() < (m)){
            for(auto x : factors[r]){
                if(x <= m) cnt[x]++;
            }
            r++;
        }
        dbg(r);
        dbg(cnt);
        if(r == n && cnt.size() < (m)) break;
        if(r == l){
            cout << 0 << endll;
            return;
        }
        ans = min(ans, arr[r - 1] - arr[l]);
        for(auto x : factors[l]){
            if(x <= m) cnt[x]--;
            if(cnt[x] == 0) cnt.erase(x);
        }
    }
    
    if(ans == INF){
        cout << -1 << endll;
        return;
    }
    cout << ans << endll;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);  

    ll T = 1;
    cin >> T;
    for(ll t = 0; t < T; t++){
        solve(t+1);
    }
}
