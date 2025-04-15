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


//13, n = 4
//should we add 8 to x?
//yes, if outer 2nd bit's set
//should we add 8 to y?
//yes, if outer 2 xor to 1
//00 11
//10 01

void solve(int num_tc)
{
    ll n;
    ll Q;
    cin >> n >> Q;
    for(ll i = 0; i < Q; i++){
        string c;
        cin >> c;
        if(c == "<-"){
            ll x = 0;
            ll y = 0;
            ll q;
            cin >> q; q--;
            ll mask = 1;
            while(q > 0){
                ll bits = q % 4;
                x |= (bits == 1 || bits == 2) * mask;
                y |= (bits & 1) * mask;
                q /= 4;
                mask *= 2;
            }
            cout << x + 1 << " " << y + 1 << endll;
        }
        else{
            ll x, y;
            cin >> x >> y;
            x--; y--;
            ll mask = 1;
            ll q = 0; 
            while(x > 0 || y > 0){
                ll bits = (y & 1);
                bits += 2 * ((bits) ^ (x & 1));
                q += bits * mask;
                x /= 2;
                y /= 2;
                mask *= 4;
            }
            cout << q + 1 << endll;
        }
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
        solve(t+1);
    }
}
