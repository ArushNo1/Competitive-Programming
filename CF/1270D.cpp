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
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> known(k);
    for(int i = 0; i < k; i++){
        cout << "?";
        for(int j = 0; j < k + 1; j++){
            if(i == j) continue;
            cout << " " << j + 1;
        }
        cout << endl;
        cin >> known[i].second >> known[i].first;
        known[i].second--;
    }
    sort(all(known));
    cout << "?";
    for(int i = 0; i < k; i++){
        cout << " " << known[i].second + 1;
    }
    cout << endl;
    int a, b;
    cin >> a >> b;
    a--;
    for(int i = 0; i < k; i++){
        if(known[i].second == a){
            cout << "! " << i + 1 << endl;
            return;
        }
    }
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
