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

//sum of the i'th shift of the array from l to
ll sumcyc(ll l, ll r, ll i, vll& pref) {
    ll n = pref.size() - 1;
    ll newl = (l + i) % n;
    ll newr = (r + i) % n;
    
    if (newr >= newl) {
        return pref[newr + 1] - pref[newl];
    } else {
        return (pref[n] - pref[newl]) + pref[newr + 1];
    }
}

void solve(int num_tc)
{
    ll n, q;
    cin >> n >> q;
    vll arr(n);
    vll pref(n + 1);
    ll sum = 0;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        sum += arr[i];
        pref[i + 1] = pref[i] + arr[i];
    }
    for(int i = 0; i < q; i++){
        ll l, r;
        cin >> l >> r;
        l--;
        ll leftblocks = l / n;
        ll rightblocks = (r) / n;
        l %= n;
        r %= n;
        ll ans = (rightblocks - leftblocks) * sum;
        if(l > 0) ans -= sumcyc(0, l - 1, leftblocks, pref);
        if(r > 0) ans += sumcyc(0, r - 1, rightblocks, pref);
        cout << ans << endll;
    }
}
//  l    r
//48324 83244 32448 24483 44832

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
