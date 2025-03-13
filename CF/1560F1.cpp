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

vll k1, k2;

void solve(int num_tc)
{
    ll n;
    cin >> n;
    ll k;
    cin >> k;
    if(k == 1){
        cout << *lower_bound(all(k1), n) << endll;
        return;
    }
    cout << *lower_bound(all(k2), n) << endll;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);  
    dbg("turn off debugging");
    ll T = 1;
    cin >> T;
    for(int c1 = 0; c1 <= 9; c1++){
        for(int c2 = c1 + 1; c2 <= 9; c2++){
            for(ll mask = 0; mask < (1 << 10); mask++){
                ll ans = 0;
                for(ll i = 0; i < 10; i++){
                    if(mask & (1 << i)){
                        ans = ans * 10 + c1;
                    }
                    else{
                        ans = ans * 10 + c2;
                    }
                    k2.push_back(ans);
                }
                
            }
            dbg(k2);
            //break;
        }
    }
    for(int i = 0; i < 10; i++){
        ll jit = i;
        for(int j = 0; j < 10; j++){
            k1.push_back(jit);
            jit = jit * 10 + i;
        }
        //k1.push_back(jit);
    }
    
    sort(all(k2));
    sort(all(k1));
    for(ll t = 0; t < T; t++){
        solve(t+1);
    }
}
