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
    //if at any point, an add, or mult hen i > 0
    int n;
    cin >> n;
    vector<pair<int, bool>> v(n, {-inf, false}); // {max_addition, has_multiply}
    for(int i = 0; i < n; i++){
        int k;
        cin >> k;
        for(int j = 0; j < k; j++){
            string s;
            int t;
            cin >> s >> t;
            if(s == "MLT" && (t > 1)){
                v[i].second = true;
            }
            else if(s == "ADD"){
                v[i].first = max(v[i].first, t);
            }
            else if(s == "SUB"){
                v[i].first = max(v[i].first, -t);
            }
        }
    }
    int tokens = 1;
    for(int i = 0; i < n; i++){
        if(tokens > 0 && v[i].second){
            cout << "YES" << endll;
            return;
        }
        else if(v[i].first > 0){
            cout << "YES" << endll;
            return;
        }
        else{
            tokens += v[i].first;
        }
    }
    cout << "NO" << endll;
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
