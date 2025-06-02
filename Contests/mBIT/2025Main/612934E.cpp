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

vector<ll> primes;
void sieve(vector<bool>& is_prime, ll n)
{
    is_prime[0] = is_prime[1] = false;
    for (ll i = 2; i <= n; i++) {
        if (is_prime[i] && (ll)i * i <= n) {
            for (ll j = i * i; j <= n; j += i)
                is_prime[j] = false;
        }
    }
}

void solve(int num_tc)
{
    int n;
    cin >> n;
    vll nums(n);
    fillv(nums, n);

    ll ans = 0;
    set<pair<ll, ll>> states;
    for(int i = 0; i < n; i++)
    {
        states.insert({nums[i], 1});
        if(states.count({1, nums[i] - 1}))
        {
            states.insert({1, nums[i]});
        }

        //prime factorize nums[i]
        if(nums[i] == 1) continue;

        for(ll j = 2; j*j <= nums[i]; j++)
        {
            if(nums[i] % j == 0)
            {
                ll fac1 = j;
                ll fac2 = nums[i] / j;
                if(states.count({fac1, fac2 - 1}))
                {
                    states.insert({fac1, fac2});
                }

                if(states.count({fac2, fac1 - 1}))
                {
                    states.insert({fac2, fac1});
                }
            }
        }
    }

    for(auto& state : states)
    {
        ans = max(ans, state.second);
    }
    cout << ans << endll;
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
