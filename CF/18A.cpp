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
    cout << __cplusplus << endll;
    pair<ll, ll> a, b, c;
    cin >> a.first >> a.second >> b.first >> b.second >> c.first >> c.second;
    auto dist = [](pair<ll, ll> a, pair<ll, ll> b) {
        return abs(a.first - b.first) * abs(a.first - b.first) + abs(a.second - b.second) * abs(a.second - b.second);
    };
    vector<ll> lens = {dist(a, b), dist(b, c), dist(c, a)};
    sort(lens.begin(), lens.end());
    if(lens[0] + lens[1] == lens[2]){
        cout << "RIGHT" << endll;
        return;
    }
    auto possible = [&](pair<ll, ll> a, pair<ll, ll> b, pair<ll, ll> c) {
        vector<ll> lens = {dist(a, b), dist(b, c), dist(c, a)};
        sort(lens.begin(), lens.end());
        return lens[0] + lens[1] == lens[2];
    };
    ll dx[] = {1, 0, -1, 0};
    ll dy[] = {0, 1, 0, -1};
    for(int i = 0; i < 4; i++){
        pair<ll, ll> a1 = {a.first + dx[i], a.second + dy[i]};
        pair<ll, ll> b1 = {b.first + dx[i], b.second + dy[i]};
        pair<ll, ll> c1 = {c.first + dx[i], c.second + dy[i]};
        if(a1 == b || a1 == c || b1 == a || b1 == c || c1 == a || c1 == b){
            continue;
        }
        if(possible(a1, b, c) || possible(a, b1, c) || possible(a, b, c1)){    
            cout << "ALMOST" << endll;
            return;
        }
    }
    cout << "NEITHER" << endll;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);  
    dbg("turn off debugging");
    ll T = 1;
    //cin >> T;
    for(ll t = 0; t < T; t++){
        solve(t+1);
    }
}
