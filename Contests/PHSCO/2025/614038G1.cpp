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
    int x;
    cin >> x;
    vector<pll> guards(n);
    for(int i = 0; i < n; i++){
        cin >> guards[i].first >> guards[i].second;
    }
    dbg(guards);
    vector<ll> numguards(201, 0);
    for(int i = 0; i < n; i++){
        for(int j = guards[i].first; j < guards[i].second; j++){
            numguards[j]++;
        }
    }
    ll maxval = 0;
    for(int i = 0; i < n; i++){
        maxval = max(maxval, guards[i].second);
    }
    for(int i = 0; i < n; i++){
        int zcount = 0;
        int start = -1;
        int value = maxval;
        for(int j = guards[i].first; j < guards[i].second; j++){
            numguards[j]--;
        }
        dbg(i);
        dbg(numguards);
        for(int j = 0; j <= guards[i].second + x; j++){
            if(numguards[j] == 0){
                zcount++;
                if(zcount == 1){
                    start = j;
                }
                if(zcount == x){
                    value = start;
                    break;
                }
            }
            else{
                zcount = 0;
                start = -1;
            }
        }
        for(int j = guards[i].first; j < guards[i].second; j++){
            numguards[j]++;
        }
        cout << value << " ";
    }
    cout << endll;
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
