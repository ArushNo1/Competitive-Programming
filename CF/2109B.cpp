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
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    int ans = inf;

    auto turns = [](int n, int m){
        int x = 0;
        while(n > 1 || m > 1){
            if(n == 1){
                while(m > 1){
                    m = (m + 1) / 2;
                    x++;
                }
                return x;
            }
            if(m == 1){
                while(n > 1){
                    n = (n + 1) / 2;
                    x++;
                }
                return x;
            }
            if(n < m){
                n = (n + 1) / 2;
                x++;
            }
            else{
                m = (m + 1) / 2;
                x++;
            }
        }
        return x;
    };

    int N = a;
    int M = m;
    ans = min(ans, turns(N, M) + 1);
    N = n - a + 1;
    ans = min(ans, turns(N, M) + 1);
    N = n;
    M = b;
    ans = min(ans, turns(N, M) + 1);
    N = n;
    M = m - b + 1;
    ans = min(ans, turns(N, M) + 1);
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
