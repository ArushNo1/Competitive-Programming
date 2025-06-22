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
//#define dbg(x)

#ifndef dbg
#define dbg(x) cerr << __LINE__ << ": " << #x << "=" << x << endl;
//edit for specific DS
#include "cp-templates/Debugging/alldebug.h"
#endif

void solve(int num_tc)
{
    ll n, k;
    string s;
    cin >> n >> k >> s;
    vll nums(n);
    fillv(nums, n);

    auto max_subarray_sum = [&](ll l, ll r){
        ll max_sum = nums[l];
        ll cur_sum = nums[l];
        for(ll i = l + 1; i <= r; i++){
            cur_sum = max(nums[i], cur_sum + nums[i]);
            max_sum = max(max_sum, cur_sum);
        }
        return max_sum;
    };
    ll start = -1;
    vector<array<ll, 3>> sums; // {start, end, sum}
    for(int e = 0; e < n; e++){
        if(s[e] == '1'){
            if(start == -1){
                start = e;
            }
        } else {
            if(start != -1){
                ll max_sum = (max_subarray_sum(start, e - 1));
                if(max_sum > k){
                    cout << "No" << endll;
                    return;
                }
                start = -1;
                sums.push_back({start, e - 1, max_sum});
            }
        }
    }
    if(start != -1){
        ll max_sum = (max_subarray_sum(start, n - 1));
        if(max_sum > k){
            cout << "No" << endll;
            return;
        }
        sums.push_back({start, n - 1, max_sum});
    }
    if(sums.size() == 0){
        cout << "Yes" << endll;
        cout << k << " ";
        for(int i = 0; i < n - 1; i++){
            cout << ll(-1e17) << " ";
        }
        cout << endll;
        return;
    }


    //all sums have been loaded in. NOw, see how to make them k

    for(auto [l, r, sum] : sums){
        if(sum == k){
            cout << "Yes" << endll;
            for(int i = 0; i < n; i++){
                if(s[i] == '1'){
                    cout << nums[i] << " ";
                } else {
                    cout << ll(-1e17) << " ";
                }
            }
            cout << endll;
            return;
        }
    }
    for(auto [l, r, sum] : sums){
        //see if left or right are available
        if(l > 0){
            if(l > 1 && s[l - 2] == '1'){
                continue;
            }
            s[l - 1] = '1';
            nums[l - 1] = 1e14;
            ll new_sum = max_subarray_sum(l - 1, r);
            new_sum -= 1e14;
            nums[l - 1] = 0;
            if(new_sum > k){
                continue;
            }
            nums[l - 1] = k - new_sum;
            if(new_sum < 0){
                nums[l - 1] = k;
            }
            cout << "Yes" << endll;
            for(int i = 0; i < n; i++){
                if(s[i] == '1'){
                    cout << nums[i] << " ";
                } else {
                    cout << ll(-1e17) << " ";
                }
            }
            cout << endll;
            return;
        }
        if(r < n - 1){
            if(r < n - 2 && s[r + 2] == '1'){
                continue;
            }
            s[r + 1] = '1';
            nums[r + 1] = 1e14;
            ll new_sum = max_subarray_sum(l, r + 1);
            new_sum -= 1e14;
            nums[r + 1] = 0;
            if(new_sum > k){
                continue;
            }
            nums[r + 1] = k - new_sum;
            if(new_sum < 0){
                nums[r + 1] = k;
            }
            cout << "Yes" << endll;
            for(int i = 0; i < n; i++){
                if(s[i] == '1'){
                    cout << nums[i] << " ";
                } else {
                    cout << ll(-1e17) << " ";
                }
            }
            cout << endll;
            return;
        }
    }
    if(s[0] == '1'){
        sums[0][0] = 0;
    }
    for(int i = 1; i < sums.size(); i++){
        dbg(i);
        //try merging two segments, ONLY if 1 zero in between them
        int r1 = sums[i - 1][1];
        int l2 = sums[i][0];
        if(l2 - r1 != 2){
            continue;
        }
        if(s[r1 + 1] == '1'){
            continue;
        }
        dbg(nums);
        dbg(sums[i - 1][0]);
        dbg(sums[i][1]);
        nums[r1 + 1] = 1e14;
        ll new_sum = max_subarray_sum(sums[i - 1][0], sums[i][1]);
        new_sum -= 1e14;
        nums[r1 + 1] = 0;
        dbg(new_sum);
        if(new_sum > k){
            continue;
        }
        s[r1 + 1] = '1';
        nums[r1 + 1] = k - new_sum;
        if(new_sum < 0){
            nums[r1 + 1] = k;
        }
        cout << "Yes" << endll;
        for(int i = 0; i < n; i++){
            if(s[i] == '1'){
                cout << nums[i] << " ";
            } else {
                cout << ll(-1e17) << " ";
            }
        }
        cout << endll;
        return;
    }
    cout << "No" << endll;
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

10
3 5
011
0 0 1

5 6
11011
4 -3 0 -2 1

4 4
0011
0 0 -4 -5

6 12
110111
1 2 0 5 -1 9

5 19
00000
0 0 0 0 0

5 19
11001
-8 6 0 0 -5

5 10
10101
10 0 10 0 10

1 1
1
0

3 5
111
3 -1 3

4 5
1011
-2 0 1 -5

*/