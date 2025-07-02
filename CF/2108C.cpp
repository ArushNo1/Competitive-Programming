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
    int n;
    cin >> n;
    vll a;
    int x;
    cin >> x;
    a.push_back(x);
    for(int i = 1; i < n; i++){
        cin >> x;
        if(x != a.back()){
            a.push_back(x);
        }
    }
    n = a.size();
    int ans = 0;
    if(n <= 2){
        cout << 1 << endll;
        return;
    }
    dbg(a);
    ans += (a[0] > a[1]);
    ans += (a[n-1] > a[n-2]);
    for(int i = 1; i < n - 1; i++){
        dbg(i);
        dbg(a[i]);
        dbg(a[i - 1]);
        dbg(a[i + 1]);
        if((a[i] > a[i - 1]) && (a[i] > a[i + 1])){
            ans++;
        }
        dbg(ans);
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
