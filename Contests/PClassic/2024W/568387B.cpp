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

bool tri_index(ll n, ll& res){
    ll low = 0, high = n - 1;
    while(low < high){
        ll mid = (low + high) / 2;
        ll mid2 = (mid) * (mid + 1) / 2;
        if(mid2 == n){
            res = mid;
            return true;
        }
        if(mid * (mid + 1) / 2 < n){
            low = mid + 1;
        }else{
            high = mid - 1;
        }
    }
    if(low * (low + 1) / 2 == n){
        res = low;
        return true;
    }
    return false;
}

void solve(int num_tc)
{
    ll n, k;
    cin >> n >> k;
    vll cactus(n);
    fillv(cactus, n);
    sort(all(cactus));
    if(cactus[0] == 1){
        cout << 0 << endll;
        return;
    }
    for(int i = 0; i < n; i++){
        ll res;
        if(!tri_index(cactus[i], res)){
            continue;
        }
        cout << (res) * (res - 1) / 2 << endll;
        return;
    }
    cout << (k) * (k + 1) / 2 << endll;
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
