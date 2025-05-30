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
    int lo = 0, hi = n;
    auto ask = [](int l, int r) {
        if (l >= r) return -1;
        cout << "? " << l + 1 << " " << r + 1 << endl;
        int ans;
        cin >> ans;
        return ans - 1;
    };

    while (hi - lo > 1) {
        int mid = (lo + hi) / 2;
        int smax = ask(lo, hi - 1);
        if (smax < mid) {
            if (ask(lo, mid - 1) == smax) {
                hi = mid;
            } else {
                lo = mid;
            }
        } else {
            if (ask(mid, hi - 1) == smax) {
                lo = mid;
            } else {
                hi = mid;
            }
        }
    }
    cout << "! " << hi << endl;
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


//1 2 3 4 5 6 7 8
//5 1 4 2 3