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

vi perm;
vi depth;
vi dist;
vi reqseen;

void disttocycle(int node, int d){
    dbg(node);
    dbg(d);
    if(depth[node] != -1){
        dbg(depth[node]);
        dbg("visited");
        dbg(reqseen);
        for(int i = depth[node]; i < d; i++){
            dist[reqseen[i]] = 0;
        }
        for(int i = 0; i < depth[node]; i++){
            dist[reqseen[i]] = depth[node] - depth[reqseen[i]];
            dbg(reqseen[i]);
            dbg(dist[reqseen[i]]);
        }
        return;
    }
    reqseen.push_back(node);
    depth[node] = d;
    int next = perm[node];
    if(dist[next] != -1){
        dbg("dist");
        dbg(next);
        dbg(dist[next]);
        dist[node] = dist[next] + 1;
        dbg(dist[node]);
        for(int i = reqseen.size() - 2; i >= 0; i--){
            dist[reqseen[i]] = dist[reqseen[i+1]] + 1;
            dbg(reqseen[i]);
            dbg(dist[reqseen[i]]);
        }
        return;
    }
    disttocycle(next, d+1);
}

void solve(int num_tc)
{
    int n;
    cin >> n;
    perm = vi(n);
    depth = vi(n, -1);
    dist = vi(n, -1);

    for(int i= 0; i < n; i++){
        cin >> perm[i];
        perm[i]--;
    }

    for(int i = 0; i < n; i++){
        if(depth[i] == -1){
            disttocycle(i, 0);
            reqseen.clear();
        }
    }
    dbg(dist);
    cout << 2 + *max_element(all(dist)) << endll;
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
