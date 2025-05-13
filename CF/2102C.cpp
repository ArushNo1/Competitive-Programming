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
    vector<vector<int>> nums(n, vector<int>(n));
    int left = 0;
    int right = n - 1; 
    int up = n - 1;
    int down = 0;
    //spiral starting from center
    int counter = n * n;
    while(counter > 0){
        for(int i = left; i <= right; i++){
            nums[up][i] = counter--;
        }
        up--;
        if(counter == 0) break;
        for(int i = up; i >= down; i--){
            nums[i][right] = counter--;
        }
        right--;
        if(counter == 0){
            break;
        }
        for(int i = right; i >= left; i--){
            nums[down][i] = counter--;
        }
        if(counter == 0) break;
        down++;
        for(int i = down; i <= up; i++){
            nums[i][left] = counter--;
        }
        left++;
    }
    dbg(nums);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << nums[i][j] - 1 << " ";
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
    cin >> T;
    for(ll t = 0; t < T; t++){
        solve(t+1);
    }
}
