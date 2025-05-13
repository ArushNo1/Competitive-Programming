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
    string s0;
    cin >> s0;

    vector<int> nums;
    nums.push_back(0);
    for(char c : s0){
        if(c == 'u'){
            nums.back()++;
        }
        else if (c == 'w' && nums.back() > 0){
            nums.push_back(0);
        }
    }
    if(nums.back() == 0){
        nums.pop_back();
    }

    //nums now stores the groups of u's, and every 2 groups of u's can all multiply
    //together to make an uwu

    //this is to compute that final product
    ll sumsqr = 0;
    ll sqrsum = 0;
    for(int i = 0; i < nums.size(); i++){
        sumsqr += nums[i] * nums[i];
        sqrsum += nums[i];
    }
    sqrsum *= sqrsum;
    ll ans = sqrsum - sumsqr;

    cout << ans / 2 << endll;
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
/*

86: "turn off debugging"=turn off debugging
76: nums=[1 1 ]
76: nums=[2 3 1 ]
76: nums=[2 2 ]
76: nums=[3 ]
*/