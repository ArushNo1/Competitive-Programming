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


void solve(int num_tc)
{
    int n;
    cin >> n;
    vvi grid(n, vi(n));
    for(int i = 0; i < n ;i++){
        for(int j = 0;j < n; j++){
            cin >> grid[i][j];
        }
        reverse(all(grid[i]));
    }
    dbg(grid);
    vvi pref(n, vi(n, 0));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n - 1; j++){
            pref[i][j + 1] = pref[i][j] + grid[i][j];
        }
    }
    sort(all(pref));
    dbg(pref);

    vector<set<int>> indeces(n);
    map<int, int> skip;

    for(int add = 1; add < n; add++){
        for(int j = 0; j < n; j++){
            if(skip.count(j)) continue;
            if(pref[j][add] == add){
                indeces[add].insert(j);
            }
        }
        if(indeces[add].size() == 0){
            cout << add << endll;
            return;
        }
        if(indeces[add].size() == 1){
            int skipr = (*indeces[add].begin());
            skip.insert({skipr, add});
            for(int j = 1; j < add; j++){
                if(indeces[add].count(skipr)){
                    indeces[add].erase(skipr);
                    if(indeces[add].size() == 0){
                        cout << add << endll;
                        return;
                    }
                }
            }
            
        }
    }
    cout << n << endll;
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
