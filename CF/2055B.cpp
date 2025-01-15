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

void solve(int num_tc)
{
    int n;
    cin >> n;
    vi a(n);
    ll asum = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        asum += a[i];
    }
    vi b(n);
    ll bsum = 0;
    for(int i = 0; i < n; i++){
        cin >> b[i];
        bsum += b[i];
    }
    if(bsum > asum){
        dbg("bsum > asum")
        cout << "NO"<< endll;
        return;
    }
    ll neededsum = 0;
    vi needed(n);
    for(int i = 0; i < n;i++){
        needed[i] = b[i] - a[i];
        neededsum += max(0, needed[i]);
    }
    dbg(neededsum);
    if((neededsum * (n - 2)) > (asum - bsum)){
        cout << "NO"<< endll;
        return;
    }
    dbg(neededsum);
    int fails = 0;
    for(int i = 0; i < n; i++){
        if(needed[i] > -neededsum){
            fails++;
            if(fails > 1){
                cout << "NO" << endll;
                return;
            }
        }
    }
    cout << "YES" << endll;
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
