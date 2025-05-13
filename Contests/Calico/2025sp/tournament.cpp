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
    vector<string> c(n);
    fillv(c, n);
    vector<ll> p(n);
    fillv(p, n);

    while(n > 1){
        dbg(c);
        dbg(p);
        vector<string> c2;
        vector<ll> p2;
        for(int i = 0; i < n / 2; i++){
            if(p[2 * i] == p[2 * i + 1]){
                p2.push_back(p[2 * i] + p[2 * i + 1]);
                c2.push_back(c[2 * i] + c[2 * i + 1]);
            }
            else if(p[2 * i] > p[2 * i + 1]){
                p2.push_back(p[2 * i] + p[2 * i + 1]);
                c2.push_back(c[2 * i]);
            }
            else{
                p2.push_back(p[2 * i + 1] + p[2 * i]);
                c2.push_back(c[2 * i + 1]);
            }
        }
        c = c2;
        p = p2;
        n /= 2;
    }
    cout << c[0] << endll;
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
