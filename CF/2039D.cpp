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

int maxn = 1e5 + 5;
vi value(maxn, 0);

void solve(int num_tc)
{
    int n, m;
    cin >> n >> m;
    vector<int> s(m);
    fillv(s, m);
    sort(all(s), greater<int>());
    vector<int> ans(n, 0);
    for(int i = 0; i < n; i++){
        ans[i] = value[i + 1];
        if(ans[i] >= m){
            cout << -1 << endll;
            return;
        }
    }
    for(int i = 0; i < n; i++){
        cout << s[ans[i]] << " ";
    }
    cout << endll;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);  
    dbg("turn off debugging");
    
    value[1] = 0;
    for(int i = 2; i < maxn; i++){
        //value[i] = 1;
        for(int j = 1; j * j <= i; j++){
            if(i % j == 0){
                value[i] = max(value[i], value[j] + 1);
                if(j != 1) value[i] = max(value[i], value[i / j] + 1);
            }
        }
    }
    
    ll T = 1;
    cin >> T;
    for(ll t = 0; t < T; t++){
        solve(t+1);
    }
}
