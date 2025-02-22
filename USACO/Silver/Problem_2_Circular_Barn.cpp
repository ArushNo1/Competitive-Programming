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

int MAXN = 5e6;
vector<int> sieve(MAXN + 1, -1);
vector<int> primes;
//-1 for prime, else min value of k

void build_sieve(){
    sieve[1] = 0;
    primes.push_back(1);
    for(int i = 2; i * i <= MAXN; i++){
        if(sieve[i] == -1){
            primes.push_back(i);
            for(int j = i; j <= MAXN; j += i){
                if(sieve[j] == -1){
                    sieve[j] = -2;
                }
            }
        }
    }
    for(int i = sqrt(MAXN); i <= MAXN; i++){
        if(sieve[i] == -1){
            primes.push_back(i);
        }
    }
}

void solve(int num_tc)
{
    ll n;
    cin >> n;
    multiset<ll> failtimes;
    multiset<ll> passtimes;
    map<int, int> cache;
    for(int i = 0; i < n; i++){
        ll x;
        cin >> x;
        if(x % 4 == 0){
            failtimes.insert(x * n / 4 + i);
            continue;
        }
        else{
            if(x % 2 == 0){
                passtimes.insert(x / 4 * n + i);
            }
            else{
                int ind = lower_bound(all(primes), x) - primes.begin();
                if(cache.count(x)){
                    passtimes.insert(cache[x] + i);
                    continue;
                }
                for(int j = ind; j >= 0; j--){
                    if(x - primes[j] % 4 == 0){
                        int res = (x - primes[j]) / 4 * n;
                        cache[x] = res;
                        passtimes.insert(res + i);
                    }
                }
            }
        }
    }
    if(failtimes.size() == 0){
        cout << "Farmer John" << endll;
        return;
    }
    if(passtimes.size() == 0){
        cout << "Farmer Nhoj" << endll;
        return;
    }
    if(*failtimes.begin() < *passtimes.begin()){
        cout << "Farmer Nhoj" << endll;
        return;
    }
    cout << "Farmer John" << endll;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);  
    dbg("turn off debugging");


    build_sieve();
    //dbg(sieve);

    ll T = 1;
    cin >> T;
    for(ll t = 0; t < T; t++){
        solve(t+1);
    }
}
