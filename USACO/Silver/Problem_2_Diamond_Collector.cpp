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

ll bestcount(vll& diamonds, ll end, ll k){
    ll best = 1;
    int l = 0;
    for(int r = 0; r < end; r++){
        while(diamonds[r] - diamonds[l] > k){
            l++;
            if(l >= r){
                break;
            }
        }
        best = max<ll>(best, r - l + 1);
    }
    return best;
}

void solve(int num_tc)
{
    ll n, k;
    cin >> n >> k;
    vll diamonds(n);
    fillv(diamonds, n);
    sort(all(diamonds));

    ll total = 1;
    int l1 = 0;
    //next to remove from the window
    for(int r1 = 0; r1 < n; r1++){
        while(diamonds[r1] - diamonds[l1] > k){
            l1++;
            if(l1 >= r1){
                break;
            }
        }
        total = max<ll>(total, r1 - l1 + 1 + bestcount(diamonds, l1, k));
    }
    cout << total << endll;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);  
    dbg("turn off debugging");
    ll T = 1;
    open("diamond");
    //cin >> T;
    for(ll t = 0; t < T; t++){
        solve(t+1);
    }
}
