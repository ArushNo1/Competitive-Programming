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
typedef long long ll;
typedef vector<ll> vll;
typedef pair<ll, ll> pll;

#define endll '\n'

#define all(x) (x).begin(), (x).end()

#define MOD ll(1e9+7)
#define inf int(1e9+1)
#define INF ll(1e18+1)

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

void solve(int num_tc)
{
    int n;
    cin >> n;
    vector<tuple<ll, ll, ll>> a(n);
    for(int i = 0; i < n; i++){
        ll x, y;
        cin >> x >> y;
        a[i] = make_tuple(x, y, i);
    }
    sort(all(a), [](const tuple<ll, ll, ll>& x, const tuple<ll, ll, ll>& y){
        return abs(get<0>(x) - get<1>(x)) > abs(get<0>(y) - get<1>(y));
    });
    vector<int> segs;
    for(int i = 0; i < n; i++){
        auto& one = a[i];
        bool fail = false;
        for(int j = 0; j < segs.size(); j++){
            auto& two = a[segs[j]];
            if((get<0>(two) <= get<0>(one) && get<1>(two) >= get<1>(one))){
                fail = true;
                break;
            }
        }
        if(!fail) segs.push_back(i);
    }
    cout << segs.size() << endll;
    for(int i = 0; i < segs.size(); i++){
        cout << get<2>(a[segs[i]]) + 1 << " ";
    }
    cout << endll;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);  
    dbg("turn off debugging");
    ll T = 1;
    cin >> T;
    for(ll t = 0; t < T; t++){
        solve(t+1);
    }
}
