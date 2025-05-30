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
    ll m, k;
    cin >> m >> k;
    vll nums;
    for(ll i = (1 << 4); i > 0; i >>= 1){
        if(k & i){
            nums.push_back((1 << i) - 1);
            m -= nums.back();
        }
    }
    dbg(nums);
    if(m < 0){
        cout << -1 << endll;
        return;
    }
    if(m == 0){
        cout << nums.size() << endll;
        for(auto i : nums){
            cout << i << " ";
        }
        cout << endll;
        return;
    }
    if(m % 2 == 0){
        nums.push_back(m / 2);
        nums.push_back(m / 2);
    }
    else{
        if(nums.back() == 1){
            nums.back()++;
            m--;
            nums.push_back(m / 2);
            nums.push_back(m / 2);
        }
        else{
            nums.push_back(1);
            nums.push_back(2);
            m -= 3;
            nums.push_back(m / 2);
            nums.push_back(m / 2);
        }
    }

    if(m < 0){
        cout << -1 << endll;
        return;
    }
    cout << nums.size() << endll;
    for(auto i : nums){
        cout << i << " ";
    }

    cout << endll;
}

void solve2(int num_tc)
{
    int n;
    cin >> n;
    if(n == -1) {
        cout << "0 0" << endll;
        return;
    }
    vll v(n);
    for(int i = 0; i < n; ++i) cin >> v[i];
    ll sum = 0;
    int xp = 0;
    for(int i = 0; i < n; ++i) {
        sum += v[i];
        xp ^= __builtin_popcountll(v[i]);
    }
    cout << sum << " " << xp << endll;
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
