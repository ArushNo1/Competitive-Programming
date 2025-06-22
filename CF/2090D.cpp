#include <iterator>
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

bool is_prime(int n) {
    if (n <= 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

void bruteforcer(int num_tc){
    int n;
    cin >> n;
    vi perm(n);
    iota(all(perm), 1);
    while(next_permutation(all(perm))){
        int numprime = 0;
        vi cvals(n);
        int sum = 0;
        for(int i = 0; i < n; i++){
            sum += perm[i];
            cvals[i] = (sum + i) / (i + 1);
            if(is_prime(cvals[i])){
                numprime++;
            }
        }
        if(numprime < (n / 3) - 1) continue;
        for(int i = 0; i < n; i++){
            cout << perm[i] << " ";
        }
        cout << endl;
        return;
    }
}

void generate_cvals(){
    int n;
    cin >> n;
    vi p(n);
    fillv(p, n);
    vi cvals(n);
    int sum = 0;
    for(int i = 0; i < n; i++){
        sum += p[i];
        cvals[i] = (sum + i) / (i + 1);
    }
    for(int i = 0; i < n; i++){
        cout << cvals[i] << " ";
    }
}
// void solve(int num_tc)
// {
//     int n;
//     cin >> n;
//     for(int i=  0; i < n - 2; i++){
//         cout << i + 1 << " ";
//     }
//     cout << n << " " << n - 1 << endll;
// }
void solve(int num_tc){generate_cvals();}

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
