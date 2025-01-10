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

//comment to enable debugging
#define dbg(x)

#ifndef dbg
#define dbg(x) cerr << __LINE__ << ": " << #x << "=" << x << endl;
//edit for specific DS
#include <alldebug.h>
#endif

ll isqrt(ll n){
    ll low = 0, high = n;
    while(low < high){
        ll mid = low + (high - low + 1) / 2;
        ll mid2 = mid * mid;
        if(mid2 == n){
            return mid;
        }
        if(mid * mid <= n){
            low = mid;
        } else {
            high = mid - 1;
        }
    }
    return low;
}

void solve(int num_tc)
{
    ll r;
    cin >> r;
    if(r == 0){
        cout << 1 << endll;
        return;
    }
    ll r2l = r * r;
    ll r2u = (r + 1) * (r + 1);
    //find all x, y such that (r+1)^2 -x^2> y^2 >= r^2-x^2

    ll ans = 0;
    //y > 0, x > 0
    ll y = r + 1;
    for(ll x = 1; x * x < r2u; x++){
        dbg(x);
        while(x * x + y * y >= r2u){
            y--;
        }
        while(x * x + y * y >= r2l){
            dbg(y);
            ans++;
            y--;
            if(y < 0){
                break;
            }
        }
        y++;
    }
    cout << ans * 4 << endll;
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
