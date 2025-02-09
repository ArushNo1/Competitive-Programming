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

//comment to enable debugging
#define dbg(x)

#ifndef dbg
#define dbg(x) cerr << __LINE__ << ": " << #x << "=" << x << endl;
//edit for specific DS
//#include "cp-templates/Debugging/alldebug.h"
#endif

void solve(int num_tc)
{
    int n, m;
    cin >> n >> m;
    vector<ll> a(n);
    bool ascending = true;
    for(int i= 0; i < n; i++){
        cin >> a[i];
        if(i > 0 && a[i] < a[i-1]) ascending = false;
    }
    vector<ll> b(m);
    for(int i= 0; i < m; i++){
        cin >> b[i];
    }
    if(ascending){
        cout << "YES" << endll;
        return;
    }
    sort(all(b));
    ll prev = min(b[0] - a[0], a[0]);
    dbg(prev);
    for(int i = 1; i < n; i++){
        dbg(i);
        dbg(prev);
        dbg(a[i]);
        int index = lower_bound(all(b), prev + a[i]) - b.begin();
        dbg(index);
        if(index == m && (a[i] < prev)){
            cout << "NO" << endll;
            return;
        }
        else if(index == m){
            prev = a[i];
            continue;
        }
        ll newprev = b[index] - a[i];
        if(a[i] < prev && newprev < prev){
            cout << "NO" << endll;
            return;
        }
        ll dist2 = a[i] - prev;
        if(dist2 >= 0){ 
            if(a[i] <= newprev)
                prev = a[i];
            else
                prev = newprev;
        }
        else{
            prev = newprev;
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
