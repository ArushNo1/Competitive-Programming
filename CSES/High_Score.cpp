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

inline void open(string name){
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
}    

//comment to enable debugging
#define dbg(x)

#ifndef dbg
#define dbg(x) cerr << __LINE__ << ": " << #x << "=" << x << endl;
//edit for specific DS
#include "cp-templates/Debugging/alldebug.h"
#endif

bool bellman_ford(vector<ll>& distance, vector<pair<pair<ll, ll>,ll>>& edges, ll x, ll n)
{
	for (int i = 0; i < n; i++) distance[i] = INF;
	distance[x] = 0;
	for (int i = 0; i < n-1; i++) 
	{
		for (auto e : edges) 
		{
			ll a, b, w;
			a = e.first.first;
			b = e.first.second;
			w = e.second;
			distance[b] = min(distance[b], distance[a] + w);
		}
	}
	
	bool negCycle = false;
	for (auto e : edges) 
	{
		ll a, b, w;
		a = e.first.first;
		b = e.first.second;
		w = e.second;
		if(distance[b] > distance[a] + w)
		{
			negCycle = true;
			break;
		}
	}
	
	return negCycle;
}
void solve(int num_tc)
{
    int n, m;
    cin >> n >> m;
    map<pair<ll, ll>,ll> edgemap;
    for(int i = 0; i < m; i++){
        ll a, b, c;
        cin >> a >> b;
        a--;
        b--;
        cin >> c;
        if(a == b) continue;
        pll edge = {a, b};
        if (edgemap.find(edge) == edgemap.end()) {
            edgemap[edge] = -c;
        } else {
            edgemap[edge] = min(edgemap[edge], -c); 
        }
    }
    vector<pair<pair<ll, ll>,ll>> edges(all(edgemap));
    vector<ll> distance(n);
    if(bellman_ford(distance, edges, 0, n)){
        cout << -1 << endll;
    }
    else{
        cout << -distance[n-1] << endll;
    }
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);  
    dbg("turn off debugging");
    ll T = 1;
    //cin >> T;
    for(ll t = 0; t < T; t++){
        solve(t+1);
    }
}
