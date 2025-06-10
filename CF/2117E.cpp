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
    vi a(n);
    fillv(a, n);
    vi b(n);
    fillv(b, n);
    vi index(n + 1, - 1);
    for(int i = n - 1; i >= 0; i--){
        if(a[i] == b[i]){
            cout << (i + 1) << endll;
            return;
        }
        if(index[a[i]] == -1){
            index[a[i]] = i;
        }
        else{
            if(index[a[i]] == (i + 1)){
                if(a[i + 1] == a[i]){
                    cout << (i + 1) << endll;
                    return;
                }
            }
            else{
                cout << (i + 1) << endll;
                return;
            }
        }
        if(index[b[i]] == -1){
            index[b[i]] = i;
        }
        else{
            if(index[b[i]] == (i + 1)){
                if(b[i + 1] == b[i]){
                    cout << (i + 1) << endll;
                    return;
                }
            }
            else{
                cout << (i + 1) << endll;
                return;
            }
        }
    }
    cout << 0 << endll;
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
