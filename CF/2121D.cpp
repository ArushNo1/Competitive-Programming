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

void bruteforcer(int num_tc)
{
    int n;
    cin >> n;
    vi a(n);
    fillv(a, n);
    vi b(n);
    fillv(b, n);
    for(int i = 0; i < n; i++){
        a[i]--;
        b[i]--;
    }
    vector<pair<int, int>> ans;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n - i - 1; j++){
            if(a[j] > a[j + 1]){
                swap(a[j], a[j + 1]);
                ans.push_back({1, j + 1});
            }
            if(b[j] > b[j + 1]){
                swap(b[j], b[j + 1]);
                ans.push_back({2, j + 1});
            }
        }
    }
    for(int i = 0; i < n; i++){
        if(a[i] > b[i]){
            swap(a[i], b[i]);
            ans.push_back({3, i + 1});
        }
    }
 
    cout << ans.size() << endll;
    for(auto [x, y] : ans){
        cout << x << " " << y << endll;
    }
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);  
    dbg("turn off debugging");
    ll T = 1;
    cin >> T;
    for(ll t = 0; t < T; t++){
        bruteforcer(t+1);
    }
}