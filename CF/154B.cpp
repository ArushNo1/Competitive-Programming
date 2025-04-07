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

vector<int> primes;
void sieve(int n) {
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= n; ++i) {
        if (is_prime[i]) {
            for (int j = i * i; j <= n; j += i) {
                is_prime[j] = false;
            }
        }
    }
    for (int i = 2; i <= n; ++i) {
        if (is_prime[i]) {
            primes.push_back(i);
        }
    }
}

void solve(int num_tc)
{
    int n, q;
    cin >> n >> q;
    //each prime factor has a list of indeces: 
    //we can count each prime that has multiple, if there still is a prime, we can conflict
    vvi prime_factors(n + 1);
    for(int i = 1; i <= n; i++){
        int x = i;
        for(int j = 0; j < primes.size() && primes[j] * primes[j] <= x; j++){
            if(x % primes[j] == 0){
                prime_factors[i].push_back(primes[j]);
                while(x % primes[j] == 0) x /= primes[j];
            }
        }
        if(x > 1){
            prime_factors[i].push_back(x);
        }
    }
    dbg(prime_factors);
    map<int, int> present; //prime factors and their number that has them
    vi turnedon(n + 1, 0);
    for(int i = 0; i < q; i++){
        char c;
        cin >> c;
        if(c == '+'){
            int x;
            cin >> x;
            if(turnedon[x]){
                cout << "Already on" << endll;
                continue;
            }
            bool conflict = false;
            for(int p : prime_factors[x]){
                if(present[p] != 0){
                    cout << "Conflict with " << present[p] << endll;
                    conflict = true;
                    break;
                }
            }
            if(conflict) continue;
            turnedon[x] = 1;
            cout << "Success" << endll;
            for(int p : prime_factors[x]){
                present[p] = x;
            }
        }
        else{
            int x;
            cin >> x;
            if(!turnedon[x]){
                cout << "Already off" << endll;
                continue;
            }
            turnedon[x] = 0;
            cout << "Success" << endll;
            for(int p : prime_factors[x]){
                present[p] = 0;
            }
        }
    }
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);  
    dbg("turn off debugging");
    ll T = 1;
    sieve(1e5 + 69);
    //cin >> T;
    for(ll t = 0; t < T; t++){
        solve(t+1);
    }
}
