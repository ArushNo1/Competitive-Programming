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

void solve(int num_tc)
{
    int n;
    cin >> n;
    vi a(n);
    for(int i =0; i < n; i++){
        cin >> a[i];
        a[i]--;
    }
    vi b(n);
    for(int i = 0; i < n ;i++){
        cin >> b[i];
        b[i]--;
    }
    auto choose2 = [](ll x){return x * (x - 1) / 2;};
    ll ans = 0;
    for(int i = 0; i < n; i++){
        if(a[i] == b[i]){
            ans += choose2(i + 1) + choose2(n - i);
            ans += min(i, n - 1 - i) + 1;
        }
    }
    for(int k = 0; k < 2; k++){
        vvi aindeces(n), bindeces(n);
        for(int i = 0; i < n; i++){
            aindeces[a[i]].push_back(i);
            bindeces[b[i]].push_back(i);
        }
        //for each i, we want to calculate min(i, n - 1 - j)
        //find n - 1 - i < j
        //then, every j lower than that contributes i + 1
        //every j after that contributes n - j
        for(int v = 0; v < n; v++){
            for(int i : aindeces[v]){
                for(int j : bindeces[v]){
                    if(i < j){
                        ans+= min(i, n - 1 - j) + 1;
                    }
                }
            }
        }
        reverse(all(a));
        reverse(all(b));
    }
    cout << ans << endll;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);  
    dbg("turn off debugging");
    ll T = 1;
    //cin >> T;
    for(ll t = 0; t < T; t++){
        solve(t+1);
    }
}
