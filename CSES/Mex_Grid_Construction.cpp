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
    vvi grid(n, vi(n, 0));
    // for(int i = 0; i < n; i++){
    //     grid[i][0] = i;
    //     grid[0][i] = i;
    // }
    // for(int i = 2; i < n; i++){
    //     grid[1][i] = i + (i % 2 == 0 ? 1 : -1);
    //     grid[i][1] = i + (i % 2 == 0 ? 1 : -1);
    // }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i == j){
                continue;
            }
            set<int> s;
            for(int r = 0; r < i; r++){
                s.insert(grid[r][j]);
            }
            for(int c = 0; c < j; c++){
                s.insert(grid[i][c]);
            }
            int mex = 0;
            while(s.count(mex)){
                mex++;
            }
            grid[i][j] = mex;
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            //int val = grid[i][j] - i;
            //cout << setw(2) << setfill(' ') << val << " ";
            
            cout << grid[i][j] << " ";
        }
        cout << endll;
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
