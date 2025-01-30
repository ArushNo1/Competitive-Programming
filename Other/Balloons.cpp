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

void solve(int num_tc)
{
    int n;
    cin >> n;
    vector<pair<int, int>> bal(n);
    for(int i = 0; i < n; i++){
        cin >> bal[i].first >> bal[i].second;
    }
    sort(all(bal));
    stack<pair<int, ld>> st;
    st.push({bal[0].first, bal[0].second});
    vector<ld> radii(n);
    radii[0] = st.top().second;

    for(int i = 1; i < n; i++){
        dbg(bal[i]);
        ld maxr = bal[i].second;
        dbg(st);
        dbg(maxr);
        while(!st.empty()){
            dbg(st.top());
            ld newr = (bal[i].first - st.top().first);
            newr *= newr;
            newr /= (4.0 * st.top().second);
            maxr = min(maxr, newr);
            dbg(newr);
            if(st.empty() || ((st.top().second + EPS) < maxr)){
                st.pop();
            }
            else{
                break;
            }
        }
        dbg(maxr);
        radii[i] = maxr;
        st.push({bal[i].first, maxr});
    }

    for(int i = 0; i < n; i++){
        cout << fixed << setprecision(4) << radii[i] << endll;
    }
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);  

    ll T = 1;
    //cin >> T;
    for(ll t = 0; t < T; t++){
        solve(t+1);
    }
}
