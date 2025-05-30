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

vector<bool> is_prime(1e7, true);
vll primes;

void solve(int num_tc)
{
    int n;
    cin >> n;
    vll nums(n);
    fillv(nums, n);
    sort(all(nums), greater<ll>());
    ll sumprimes = 0;
    for(int i = 0; i < n; i++){
        sumprimes += primes[i];
    }
    ll sumnums = 0;
    for(int i = 0; i < n; i++){
        sumnums += nums[i];
    }
    ll ans = 0;
    while(sumprimes > sumnums){
        ans++;
        sumprimes -= primes[n - 1];
        sumnums -= nums[n - 1];
        n--;
        if(n == 0) break;
    }
    cout << ans << endll;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);  
    dbg("turn off debugging");

    for(ll i = 2; i < is_prime.size(); i++) {
        if(is_prime[i]) {
            primes.push_back(i);
            for(ll j = i * i; j < is_prime.size(); j += i) {
                is_prime[j] = false;
            }
        }
    }

    ll T = 1;
    cin >> T;
    for(ll t = 0; t < T; t++){
        solve(t+1);
    }
}
