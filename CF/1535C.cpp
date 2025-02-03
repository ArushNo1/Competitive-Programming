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
#include <alldebug.h>
#endif

void solve(int num_tc) {
    string s;
    cin >> s;
    int n = s.size();

    //parity, value
    vector<vector<vector<int>>> last(n, vector<vector<int>>(2, vector<int>(2, -1)));
    
    // Initialize first position
    if(s[0] != '?') {
        last[0][0][s[0] - '0'] = 0;
    }
    
    for(int i = 1; i < n; i++) {
        last[i][0][0] = last[i - 1][0][0];
        last[i][0][1] = last[i - 1][0][1];
        last[i][1][0] = last[i - 1][1][0];
        last[i][1][1] = last[i - 1][1][1];
        if(s[i] != '?') {
            last[i][i % 2][s[i] - '0'] = i;
        }
    }

    ll ans = 0;
    for(int r = 0; r < n; r++) {
        if(s[r] == '?') {
            int l1 = last[r][r % 2][0];
            l1 = max(l1, last[r][1 - (r % 2)][1]);
            int l2 = last[r][r % 2][1];
            l2 = max(l2, last[r][1 - (r % 2)][0]);
            ans += r - min(l1, l2);
            continue;
        }
        int l = last[r][r % 2][1 - (s[r] - '0')];
        l = max(l, last[r][1 - (r % 2)][s[r] - '0']);
        ans += r - l;
    }
    cout << ans << endl;
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
