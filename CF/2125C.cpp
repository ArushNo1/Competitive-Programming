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
    vll nums1 = {2, 3, 5, 7};
    vll nums2 = {6, 10, 14, 15, 21, 35};
    vll nums3 = {2 * 3 * 5, 2 * 3 * 7, 2 * 5 * 7, 3 * 5 * 7};
    vll nums4 = {2 * 3 * 5 * 7};
    ll l, r;
    cin >> l >> r;
    ll sum = 0;
    for(ll i : nums1){
        sum -= (r / i) - ((l - 1) / i);
    }
    for(ll i : nums2){
        sum += (r / i) - ((l - 1) / i);
    }
    for(ll i : nums3){
        sum -= (r / i) - ((l - 1) / i);
    }
    for(ll i : nums4){
        sum += (r / i) - ((l - 1) / i);
    }
    cout << (r - l + 1) + sum << endll;
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
