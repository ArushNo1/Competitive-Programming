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
typedef __int128_t ll;
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
    vll x(n);
    vll y(n);
    for(int i= 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        x[i] = a;
        y[i] = b;
    }
    if(n == 1){
        cout << 0 << endll;
        return;
    }
    sort(all(x));
    sort(all(y));
    for(int i = 1; i < n; i++){
        x[i] -= x[0];
        y[i] -= y[0];
    }
    x[0] = 0;
    y[0] = 0;
    ll ans = 0;
    ll sumx = x[0], sumy = y[0];
    for(ll i = 1; i < n; i++){
        ans += i * x[i] - sumx;
        sumx += x[i];
        ans += i * y[i] - sumy;
        sumy += y[i];
    }
    auto int128_to_string = [](ll value) -> string {
        if (value == 0) return "0";
        bool neg = value < 0;
        string res;
        ll v = value;
        if (neg) v = -v;
        while (v > 0) {
            res += '0' + int(v % 10);
            v /= 10;
        }
        if (neg) res += '-';
        reverse(res.begin(), res.end());
        return res;
    };
    cout << int128_to_string(ans) << endll;
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
