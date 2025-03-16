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
typedef long long ll;
typedef vector<ll> vll;
typedef long double ld;
typedef pair<ll, ll> pll;
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

bool pos2(vi& a){
    deque<int> d;
    d.push_back(a[0]);
    for(int i = 1; i < a.size(); i++){
        if(a[i] >= d.back()){
            d.push_back(a[i]);
        }
        else if(a[i] <= d.front()){
            d.push_front(a[i]);
        }
        else{
            return false;
        }
    }
    return true;
}

bool possible(vi& a, int skip){
    if(skip == 0){
        int lo = a[1], hi = a[1];
        for(int i = 2; i < a.size(); i++){
            if(a[i] <= lo){
                lo = a[i];
            }
            else if(a[i] >= hi){
                hi = a[i];
            }
            else{
                return false;
            }
        }
        return true;
    }
    int lo = a[0], hi = a[0];
    for(int i = 1; i < a.size(); i++){
        if(i == skip) continue;
        if(a[i] <= lo){
            lo = a[i];
        }
        else if(a[i] >= hi){
            hi = a[i];
        }
        else{
            return false;
        }
    }
    return true;
}

void solve(int num_tc)
{
    int n;
    cin >> n;
    vi arr(n);
    fillv(arr, n);
    if(pos2(arr)){
        cout << "YES" << endll;
        return;
    }
    if(n >= 400){
        for(int i = 0; i < n; i++){
            if(possible(arr, i)){
                cout << "YES" << endll;
                return;
            }
        }
        cout << "NO" << endll;
        return;
    }
    
    for(int l = 0; l < n; l++){
        for(int r = l + 1; r < n; r++){
            //cyclic shift the array a[l ... r] to the left
            vi temp;
            for(int i = 0; i < l; i++){
                temp.push_back(arr[i]);
            }
            for(int i = l + 1; i <= r; i++){
                temp.push_back(arr[i]);
            }
            temp.push_back(arr[l]);
            for(int i = r + 1; i < n; i++){
                temp.push_back(arr[i]);
            }
            if(pos2(temp)){
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