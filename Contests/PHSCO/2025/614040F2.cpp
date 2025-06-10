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
    vector<vector<pair<int, ll>>> juncs(n);
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        for(int j = 0; j < a; j++){
            string s;
            cin >> s;
            ll t;
            cin >> t;
            if(s == "MLT"){
                juncs[i].emplace_back(0, t);
            } else if(s == "ADD"){
                juncs[i].emplace_back(1, t);
            } else{
                juncs[i].emplace_back(2, t);
            }
        }
    }
    dbg(juncs);
    vector<ll> flippers(n, 0);//0 if no mlt -1, 1 if optional, 2 if mandatory
    for(int i = 0; i < n; i++){
        int num_1 = 0;
        for(auto& [type, t] : juncs[i]){
            if(type != 0) continue; 
            if(t < 0){
                num_1++;
            }
        }
        if(num_1 == 0){
            flippers[i] = 0; 
        } else if(num_1 < juncs[i].size()){
            flippers[i] = 1;
        } else{
            flippers[i] = 2;
        }
    }
    dbg(flippers);
    //at each position, calcualte if it's possible to go through an even number of mlt
    // if it's possible to go through an odd number of mlt
    int num1 = 0, num2 = 0;
    for(int i = n - 1; i >= 0; i--){
        num1 += (flippers[i] == 1);
        num2 += (flippers[i] == 2);
        bool containadd = false;
        bool containsub = false;
        for(auto& [type, t] : juncs[i]){
            if(type == 1) containadd = true;
            if(type == 2) containsub = true;
            if(type == 0){
                if(t > 1){
                    containadd = true;
                }
            }
        }
        //if add and even number of mlt
        if(containadd){
            if(num2 % 2 == 0 || num1 > 0){
                cout << "YES" << endll;
                return;
            }
        }
        if(containsub){
            if(num2 % 2 == 1 || num1 > 0){
                cout << "YES" << endll;
                return;
            }
        }
        
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
