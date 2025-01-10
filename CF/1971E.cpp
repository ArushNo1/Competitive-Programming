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
    int n, k, q;
    cin >> n >> k >> q;
    vector<pair<ll, ll>> known;
    known.push_back({0, 0});
    for(int i = 0; i < k; i++){
        int t;
        cin >> t;
        known.push_back({t, 0});
    }
    for(int i = 0; i < k; i++){
        cin >> known[i + 1].second; 
    }
    dbg(known);
    //position, time

    for(int i = 0; i < q; i++){
        ll d;
        cin >> d;
        if(d == 0){
            cout << "0 ";
            continue;
        }
        dbg(d);
        ll pos = upper_bound(all(known), make_pair(d, -1ll)) - known.begin();
        cout << fixed << (known[pos - 1].second) + ll((d - known[pos - 1].first) * (known[pos].second - known[pos - 1].second) / (known[pos].first - known[pos - 1].first)) << " ";
    }
    cout << endll;
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
