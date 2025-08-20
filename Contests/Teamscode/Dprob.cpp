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
    ll n, x, y;
    cin >> n >> x >> y;
    ll sum = 0;
    vll a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
        sum += a[i];
    }

    int fav = -1;
    ll favdelta = -INF;
    bool multi = false;
    for(int i = 0; i < n; i++){
        ll delta = (a[i] & y) - a[i];
        //maximize delta
        if(delta > favdelta){
            favdelta = delta;
            fav = i;
            multi = false;
        }
        else if(delta == favdelta){
            multi = true;
        }
    }
    ll best = INF;
    for(int i = 0; i < n; i++){
        ll oldai = a[i];
        a[i] = (a[i] | x);
        ll delta = a[i] - oldai;
        if(i == fav && !multi){
            ll bobdelta = -INF;
            for(int j = 0; j < n; j++){
                bobdelta = max(bobdelta, (a[j] & y) - a[j]);
            }            
            best = min(best, sum + delta + bobdelta);
        }
        ll bobdelta = favdelta;
        bobdelta = max(bobdelta, (a[i] & y) - a[i]);
        best = min(best, sum + delta + bobdelta);
        a[i] = oldai;
    }
    cout << best << endll;
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
