#include <algorithm>
#include <cstdint>
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
//!#define dbg(x)

#ifndef dbg
#define dbg(x) cerr << __LINE__ << ": " << #x << "=" << x << endl;
//edit for specific DS
#include "cp-templates/Debugging/alldebug.h"
#endif

ll subsolve(int n, vll& a, ll x, ll s){
    if(n == 0) return 0;
    dbg(a);
    vll pref(n + 1, 0); 
    for(int i = 0; i < n; i++){
        pref[i + 1] = pref[i] + a[i];
        pref[i] = pref[i + 1];
    }
    pref.pop_back();
    dbg(pref);
    ll ans = 0;
    
    return ans;
}

void bruteforcer(int num_tc)
{
    ll n, s, x;
    cin >> n >> s >> x;
    vll a(n);
    vi xs;
    vi gxs;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    ll ans = 0;
    vll current;
    for(int i = 0; i < n; i++){
        if(a[i] > x){
            ans += subsolve(current.size(), current, x, s);
            current.clear();
        }
        current.push_back(a[i]);
    }
    ans += subsolve(current.size(), current, x, s);
    cout << ans << endll;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);  
    dbg("turn off debugging");
    ll T = 1;
    cin >> T;
    for(ll t = 0; t < T; t++){
        bruteforcer(t+1);
    }
}
