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
//!#define dbg(x)

#ifndef dbg
#define dbg(x) cerr << __LINE__ << ": " << #x << "=" << x << endl;
//edit for specific DS
#include "cp-templates/Debugging/alldebug.h"
#endif

vi slice_vector(vi v, int l, int r){
    vi res;
    for(int i = l; i < r; i++){
        res.push_back(v[i]);
    }
    return res;
}

bool simul(vi v, int l, int r, int x){
    int g = 0;
    for(int i = l; i <= r; i++){
        g += v[i];
        if(g >= x) g = 0;
    }
    return g != 0;
}

void solve(int num_tc)
{
    int n, x;
    cin >> n >> x;
    vi mush(n);
    fillv(mush, n);

    // for(int r = 0; r < n; r++){
    //     if(mush[r] >= x){
    //         continue;
    //     }

    // }
    for(int l = 0; l < n; l++){
        for(int r = l; r < n; r++){
            if(simul(mush, l, r, x)){
                dbg(slice_vector(mush, l, r));
            }
        }
    }
}

/*
3 2
1 2 3

either the overflow happens on the previous day or none at all

*/

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
