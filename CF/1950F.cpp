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
//#include <alldebug.h>
#endif

void solve(int num_tc)
{
    int a, b, c;
    cin >> a >> b >> c;
    if(c == 0){
        cout << -1 << endll;
        return;
    }
    if(c != a + 1){
        cout << -1 << endll;
        return;
    }
    if(c == 1 && (a + b) == 0){
        cout << 0 << endll;
        return;
    }
    if(a == 0){
        cout << b << endll;
        return;
    }
    int aheight = 0;
    int alimit = 0;
    for(int i = 0; i < a; i++){
        alimit = (1 << (i + 1)) - 1;
        if(alimit >= a){
            aheight = i;
            break;
        }
    }
    dbg(aheight);
    dbg(alimit);
    //int nodesperlayer = c;
    int spaceleft = alimit - a;
    int j = min(b, spaceleft);
    dbg(j);
    b -= j;
    spaceleft -= j;
    dbg(spaceleft);
    if(b == 0){
        cout << aheight + 1 << endll;
        return;
    }
    dbg(b);
    cout << (aheight + ll(ceil(b * 1.0 / c) + 1) ) << endll;
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
