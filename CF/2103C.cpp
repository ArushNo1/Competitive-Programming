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
//!#define dbg(x)

#ifndef dbg
#define dbg(x) cerr << __LINE__ << ": " << #x << "=" << x << endl;
//edit for specific DS
#include "cp-templates/Debugging/alldebug.h"
#endif

void solve(int num_tc)
{
    int n, k;
    cin >> n >> k;
    vi nums(n);
    for(int i = 0; i < n ;i++){
        int x;
        cin >> x;
        nums[i] = (x > k);
    }
    if(nums[0] == 0 && nums[1] == 0){
        cout << "YES" << endll;
        return;
    }
    if(nums[n - 1] == 0 && nums[n - 2] == 0){
        cout << "YES" << endll;
        return;
    }
    int leftans = -1;
    int counter = 0;
    for(int i = 0; i < n; i++){
        if(nums[i] == 1) counter++;
        else counter--;
        if(counter <= 0){
            leftans = i;
            break;
        }
    }
    int rightans = -1;
    counter = 0;
    for(int i = n- 1; i >= 0; i--){
        if(nums[i] == 1) counter++;
        else counter--;
        if(counter <= 0){
            rightans = i;
            break;
        }
    }
    dbg(leftans);
    dbg(rightans);
    if(leftans >= 0 && rightans >= 0 && (leftans + 1 < rightans)){
        cout << "YES" << endll;
        return;
    }
    //try left and middle
    int midans = -1;
    counter = 0;
    for(int i = leftans + 1; i < n; i++){
        dbg(i);
        dbg(nums[i]);
        if(nums[i] == 1) counter++;
        else counter--;
        dbg(counter);
        if(counter <= 0){
            midans = i;
            break;
        }
    }
    dbg(midans);
    dbg(counter);
    if(midans >= 0 && midans + 1 < n){
        cout << "YES" << endll;
        return;
    }
    midans = -1;
    counter = 0;
    for(int i = rightans - 1; i > 0; i--){
        if(nums[i] == 1) counter++;
        else counter--;
        if(counter <= 0){
            midans = i;
            break;
        }
    }
    if(midans > 0){
        cout << "YES" << endll;
        return;
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
