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

ll invMod(ll x) {
    if (x <= 1) {
      return x;
    }
    return MOD - MOD / x * invMod(MOD % x) % MOD;
  }
template<typename T>
T binom(T n, T k){
    if(k > n - k){
        k = n - k;
    }
    T value = 1;
    for (T i = 1; i <= k; ++i) {
        value = (((value * (n - i + 1)) % MOD) * invMod(i)) % MOD;
    }
    return value;
}
void solve(int num_tc)
{
    int n, k;
    cin >> n >> k;
    
    map<ll, ll, greater<int>> counts;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        counts[x - 1]++;
    }
    if(k >= n){
        cout << 1 << endll;
        return;
    }
    auto j = counts.begin();
    while(k >= j->second){
        k -= j->second;
        j++;
    }
    dbg(*j);
    dbg(k);
    cout << binom<ll>(j->second, k) << endll;
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
