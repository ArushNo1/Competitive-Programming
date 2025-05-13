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
    using ld = long double;
    ld EPS = 1e-7;
    ld r, x1, x2, y1, y2;
    cin >> r >> x1 >> y1 >> x2 >> y2;
    //flat is at 1, fafa at 2

    auto dist = [](ld x1, ld y1, ld x2, ld y2){
        return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));  
    };
    ld cdist = dist(x1, y1, x2, y2);
    if(cdist - r > -EPS){
        cout << fixed << setprecision(20) << x1 << " " << y1 << " " << r << endll;
        return;
    }
    ld theta = atan2(y1 - y2, x1 - x2);
    ld longest = (r + cdist) / 2;
    cout << fixed << setprecision(20) << (x2 + longest * cos(theta)) << " " << (y2 + longest * sin(theta)) << " " << (longest) << endll;
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
