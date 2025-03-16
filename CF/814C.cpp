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
    string s;
    cin >> s;
    int q;
    cin >> q;
    for(int _ = 0; _ < q; _++){
        int m;
        cin >> m;
        char c;
        cin >> c;
        //in each window:
        //left, right, num c's, num not c's (< m)
        int maxl = m;
        int l = 0;
        int ncs = 0;
        int cs = 0;
        for(int r = 0; r < n; r++){
            if(s[r] == c){
                cs++;
                maxl = max(maxl, r - l + 1);
                continue;
            }
            ncs++;
            if(ncs <= m){
                maxl = max(maxl, r - l + 1);
                continue;
            }
            while(ncs > m){
                if(s[l] == c){
                    cs--;
                }
                else{
                    ncs--;
                }
                l++;
            }
            maxl = max(maxl, r - l + 1);
        }
        cout << maxl << endll;
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
