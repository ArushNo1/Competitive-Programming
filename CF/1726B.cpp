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

void solve(int num_tc)
{
    ll n, m;
    cin >> n >> m;
    vll ans(n, 1);
    if(m < n){
        cout << "No" << endll;
        return;
    }
    if(n % 2 == 1){
        ans[0] = m - (n - 1);
        if(ans[0] <= 0){
            cout << "No" << endll;
            return;
        }
        cout << "Yes" << endll;
        for(int i = 0; i < n; i++){
            cout << ans[i] << " ";
        }
        cout << endll;
        return;
    }
    for(int i = 1; i <= n; i++){
        if((n - i) % 2 != 0) continue;
        int m2 = m - (n - i);
        if(m2 < 0) continue;
        if(m2 % i != 0) continue;
        for(int j = 0; j < i; j++){
            ans[j] = m2 / i;
        }
        for(int j = i; j < n; j++){
            ans[j] = 1;
        }
        cout << "Yes" << endll;
        for(int j = 0; j < n; j++){
            cout << ans[j] << " ";
        }
        cout << endll;
        return;
    }
    cout << "No" << endll;
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
