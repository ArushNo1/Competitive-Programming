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


ll minarea(int n, vector<pll>& cows){
    sort(all(cows));
    ll ymax = -inf;
    ll ymin = inf;
    vll prefmax(n);
    vll prefmin(n);
    //prefmax[i] is the largest y among the cows[0...i]
    for(int i = 0; i < n; i++){
        ymax = max(ymax, cows[i].second);
        ymin = min(ymin, cows[i].second);
        prefmax[i] = ymax;
        prefmin[i] = ymin;
    }
    vll suffmax(n);
    vll suffmin(n);
    ymax = -inf;
    ymin = inf;
    //prefmax[i] is hte largest y among the cows[i...n-1]
    for(int i = n - 1; i >= 0; i--){
        ymax = max(ymax, cows[i].second);
        ymin = min(ymin, cows[i].second);
        suffmax[i] = ymax;
        suffmin[i] = ymin;
    }
    dbg(prefmax);
    dbg(prefmin);
    dbg(suffmax);
    dbg(suffmin);

    ll area = INF;
    //cows 0 ... i are in the first bin, i + 1 ... n - 1 are in the second
    for(int i = 0; i < n - 1; i++){
        ll y1 = prefmax[i] - prefmin[i];
        ll y2 = suffmax[i + 1] - suffmin[i + 1];
        area = min(area, (y1 * (cows[i].first - cows[0].first)) + (y2 * (cows[n - 1].first - cows[i + 1].first)));
    }
    return area;
}

void solve(int num_tc)
{
    int n;
    cin >> n;
    //sufmax[i] = maximum y value across all cows from cow i on (in x value)
    vector<pll> cows(n);
    ll maxx = -inf, maxy = -inf, minx = inf, miny = inf;
    for(int i = 0; i < n;i ++){
        cin >> cows[i].first >> cows[i].second;
        maxx = max(maxx, cows[i].first);
        minx = min(minx, cows[i].first);
        maxy = max(maxy, cows[i].second);
        miny = min(miny, cows[i].second);
    } 
    ll initial = (maxx - minx) * (maxy - miny);
    ll area = minarea(n, cows);
    for(int i = 0; i < n; i++){
        swap(cows[i].first, cows[i].second);
    }
    sort(all(cows));
    area = min(area, minarea(n, cows));
    cout << initial - area << endll;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);  
    dbg("turn off debugging");
    //open("split");
    ll T = 1;
    //cin >> T;
    for(ll t = 0; t < T; t++){
        solve(t+1);
    }
}
