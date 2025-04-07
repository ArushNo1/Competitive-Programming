#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

typedef tree<int, null_type, less<int>, rb_tree_tag,
             tree_order_statistics_node_update>
    indexed_set;

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

#define MOD ll(1e9 + 7)
#define inf int(1e9 + 1)
#define INF ll(1e18 + 1)
#define EPS ld(1e-9)

template <typename T> inline void fillv(vector<T> &v, int n) {
    for (int i = 0; i < n; ++i) {
        std::cin >> v[i];
    }
}

inline void open(string name) {
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
}

// comment to enable debugging
#define dbg(x)

#ifndef dbg
#define dbg(x) cerr << __LINE__ << ": " << #x << "=" << x << endl;
// edit for specific DS
#include "cp-templates/Debugging/alldebug.h"
#endif

long long binExp(long long a, long long b) {
    if (b == 0)
        return 1;

    long long res = binExp(a, b / 2) % MOD;
    if (b & 1) {
        return (a * ((res * res) % MOD)) % MOD;
    } else
        return (res * res) % MOD;
}

long long binExp(long long a, long long b, long long mod) {
    if (b == 0)
        return 1;

    long long res = binExp(a, b / 2) % mod;
    if (b & 1) {
        return (a * ((res * res) % mod)) % mod;
    } else
        return (res * res) % mod;
}
ll invMod(ll x) {
    if (x <= 1) {
      return x;
    }
    return MOD - MOD / x * invMod(MOD % x) % MOD;
}


void solve(int num_tc) {
    ll n;
    cin >> n;
    ll numdiv = 1;             
    ll numdiv_exp = 1;          
    ll sumdiv = 1;                  
    ll number = 1;           
    ll proddiv = 1;

    for (int i = 0; i < n; i++) {
        ll p, e;
        cin >> p >> e;

        proddiv = binExp(proddiv, e + 1);
        ll multterm = binExp(p, e * (e + 1) / 2);
        multterm = binExp(multterm, numdiv_exp);
        proddiv = (proddiv * multterm) % MOD;

        numdiv = (numdiv * (e + 1ll)) % MOD;
        numdiv_exp = (numdiv_exp * (e + 1ll)) % (MOD - 1ll);

        ll addTerm = (binExp(p, e + 1ll, MOD) - 1 + MOD) % MOD;
        addTerm = (addTerm * invMod((p - 1 + MOD) % MOD)) % MOD;
        sumdiv = (sumdiv * addTerm) % MOD;

        number = (number * binExp(p, e, MOD)) % MOD;

        
    }
    cout << numdiv << " " << sumdiv << " " << proddiv << endll;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    dbg("turn off debugging");
    ll T = 1;
    // cin >> T;
    for (ll t = 0; t < T; t++) {
        solve(t + 1);
    }
}
