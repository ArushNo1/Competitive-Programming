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

ll invMod(ll x) {
  if (x <= 1) {
    return x;
  }
  return MOD - MOD / x * invMod(MOD % x) % MOD;
}

long long binExp(long long a, long long b) {
  if (b == 0)
    return 1;

  long long res = binExp(a, b / 2) % MOD;
  if (b & 1) {
    return (a * ((res * res) % MOD)) % MOD;
  } else
    return (res * res) % MOD;
}


void solve(int num_tc)
{
    vector<bool> is_prime(2e5 + 5, true);
    vector<pll> primes;
    for(ll i = 2; i < 2e5 + 2; i++){
        if(is_prime[i]){
            primes.push_back({i, 0});
            for(ll j = i * i; j < 2e5 + 2; j += i){
                is_prime[j] = false;
            }
        }
    }
    int n;
    cin >> n;
    vll perm(n);
    for(int i = 0; i < n; ++i) {
        cin >> perm[i];
        perm[i]--;
    }
    ll l = 1;
    vector<bool> visited(n, false);
    for(ll i = 0; i < n; i++){
        if(visited[i]) continue;
        ll cur = i;
        ll cnt = 0;
        while(!visited[cur]) {
            visited[cur] = true;
            cur = perm[cur];
            cnt++;
        }
        for(int p = 0; p < primes.size(); p++){
            if(cnt == 1) break;
            ll ex = 0;
            while(cnt % primes[p].first == 0){
                cnt /= primes[p].first;
                ex++;
            }
            primes[p].second = max(ex, primes[p].second);
        }
    }
    for(auto& x : primes){
        l = l * binExp(x.first, x.second);
        l %= MOD;
    }
    cout << l << endll;
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
