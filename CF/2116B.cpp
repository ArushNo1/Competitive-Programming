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

vll pow2(1e5 + 5);

void solve(int num_tc)
{
    int n;
    cin >> n;
    vll a(n);
    fillv(a, n);
    vll b(n);
    fillv(b, n);
    
    vll maxinda(n);
    ll minda = 0;
    vll maxindb(n);
    ll mindb = 0;
    for(int i = 0; i < n; i++){
        if(a[i] > a[minda]){
            minda = i;
        }
        maxinda[i] = minda;
        if(b[i] > b[mindb]){
            mindb = i;
        }
        maxindb[i] = mindb;
    }
    for(int i = 0; i < n; i++){
        ll ans1 = a[maxinda[i]] * 1e5 + b[i - maxinda[i]];
        ll ans2 = b[maxindb[i]] * 1e5 + a[i - maxindb[i]];
        if(ans1 > ans2){
            cout << (pow2[a[maxinda[i]]] + pow2[b[i - maxinda[i]]]) % MOD<< " ";
        }
        else{
            cout << (pow2[b[maxindb[i]]] + pow2[a[i - maxindb[i]]]) % MOD << " ";
        }
    }
    dbg(maxinda);
    dbg(maxindb);
    cout << endll;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);  
    dbg("turn off debugging");
    pow2[0] = 1;
    for(int i = 1; i < pow2.size(); i++){
        pow2[i] = (pow2[i-1] * 2) % MOD;
    }
    ll T = 1;
    cin >> T;
    for(ll t = 0; t < T; t++){
        solve(t+1);
    }
}