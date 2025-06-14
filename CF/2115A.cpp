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

ll maxai = 5006;
void solve(int num_tc)
{
    int n;
    cin >> n;
    vll nums(n);
    fillv(nums, n);
    ll g = nums[0];
    for(int i = 1; i < n; i++){
        g = __gcd(g, nums[i]);
    }
    for(auto &x : nums){
        x /= g;
    }
    dbg(nums);
    vll dp(maxai + 1, inf);
    for(auto i : nums){
        dp[i] = 0;
    }
    if(dp[1] == 0){
        cout << n - count(all(nums), 1) << endll;
        return;
    }
    for(int i = maxai; i >= 1; i--){
        for(int j = 0; j < n; j++){
            dbg(i);
            dbg(nums[j]);
            ll x = gcd(i, nums[j]);
            dbg(x);
            dp[x] = min(dp[x], dp[i] + 1);
            dbg(dp[i]);
            dbg(dp[x]);
        }
    }
    dbg(dp);
    cout << dp[1] + (n - 1) << endll;
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
