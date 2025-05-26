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
#define MOD ll(998244353)
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

ll invMod(ll x) {
  if (x <= 1) {
    return x;
  }
  return MOD - MOD / x * invMod(MOD % x) % MOD;
}

vll fact;
vll infact;

struct Solution {
    vll fullset;    
    ll fullsum = 0;
    ll bigsum = 0;
    ll ans = 0;
    ll denom = 1;
    int n = 0;
    void solve(int num_tc)
    {
        for(int i = 0; i < 26; i++){
            int x;
            cin >> x;
            if(x > 0) {
                fullset.push_back(x);
                fullsum += x;
                denom = (denom * infact[x]) % MOD;
            }
        }
        n = fullset.size();
        bigsum = fullsum - fullsum / 2;
        
        vll dp(bigsum + 1, 0);
        dp[0] = 1;
        for(int i = 0; i < n; i++){
            for(int j = bigsum; j >= fullset[i]; j--){
                dp[j] = (dp[j] + dp[j - fullset[i]]) % MOD;
            }
        }
        ans = dp[bigsum];

        ans = (ans * fact[bigsum] % MOD * fact[fullsum - bigsum] % MOD * denom) % MOD;
        cout << ans << endll;
    }
};

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);  
    dbg("turn off debugging");

    fact.resize(5e5 + 5);
    infact.resize(5e5 + 5);
    fact[0] = 1;
    for(ll i = 1; i < 5e5 + 5; i++){
        fact[i] = (fact[i - 1] * i) % MOD;
    }
    infact[5e5 + 4] = invMod(fact[5e5 + 4]);
    for(ll i = 5e5 + 3; i >= 0; i--){
        infact[i] = (infact[i + 1] * (i + 1)) % MOD;
    }


    ll T = 1;
    cin >> T;
    for(ll t = 0; t < T; t++){
        Solution().solve(t+1);
    }
}
