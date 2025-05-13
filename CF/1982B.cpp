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
    int x, k, y;
    cin >> x >> y >> k;
    k--;
    x++;
    while(x % y == 0) x /= y;
    while(k > 0 && x >= y){
        dbg(x);
        dbg(k);
        int nextnum = (x / y + 1) * y;
        dbg(nextnum);
        int numops =  nextnum - x;
        if(numops > k){
            cout << x + k << endll;
            return;
        }
        k -= numops;
        x = nextnum;
        while(x % y == 0){
            x /= y;
        }
    }
    if(k == 0){
        cout << x << endll;
        return;
    }
    dbg("end of loop");
    dbg(k);
    dbg(x);
    int numops = y - x;
    dbg(numops);
    if(numops > k){
        cout << x + k << endll;
        return;
    }
    k -= numops;
    x = 1;
    if(k == 0) {
        cout << 1 << endll; 
        return;
    }
    k %= (y - 1);
    x += k;
    cout << x << endl;
    // while(k--){
    //     x++;
    //     while(x % y == 0) x /= y;
    //     dbg(k);
    //     dbg(x);
    // }
    // cout << x << endll;
}
/*
83: k=9
84: x=12345679

83: k=8
84: x=12345680

83: k=7
84: x=4115227

83: k=6
84: x=4115228

83: k=5
84: x=1371743

83: k=4
84: x=152416

83: k=3
84: x=152417

83: k=2
84: x=50806

83: k=1
84: x=50807

83: k=0
84: x=16936
*/

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
