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
typedef unsigned long long ull;
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

inline ull msb(ull x){
    return 63 - __builtin_clzll(x);
}

string bin(ull x){
    return bitset<16>(x).to_string();
}

void solve(int num_tc)
{
    ull n;
    ull x;
    string s;
    cin >> n >> x >> s;
    for(char q : s){
        if(q == 'U'){
            if(x == 1){
                cout << -1 << endll;
                return;
            }
            ull mask = 1 << (msb(x));
            x = x ^ mask;
            ull submask = mask >> 1;
            x = x | submask;
            continue;
        }
        ull LR = q == 'R' ? 1 : 0;
        ull mask = 1 << (msb(x));
        ull supermask = mask << 1;
        ull smallchild = (x | supermask) ^ mask; //moves the msb 1 to the left
        ull childrenareflipped = ((n - smallchild) & mask) > 0;
        if(childrenareflipped == LR){
            x = smallchild;
        }
        else{
            x = smallchild + mask;
        }
        if(x > n){
            cout << -1 << endll;
            return;
        }
    }
    cout << x << endll;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);  
    dbg("turn off debugging");
    ull T = 1;
    cin >> T;
    for(ull t = 0; t < T; t++){
        solve(t+1);
    }
}
