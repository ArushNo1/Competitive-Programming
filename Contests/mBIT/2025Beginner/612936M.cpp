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
    ll n, s;
    cin >> n >> s;
    vector<vll> times(n);
    for(int i = 0; i < n ;i++){
        ll a, b;
        cin >> a >> b;
        times[a - 1].push_back(b);
    }
    for(int i = 0; i < n; i++){
        sort(all(times[i]));
    }
    vector<pll> intervals;
    for(int i = 0; i < n; i++){
        if(times[i].size() == 0) continue;
        for(int j = 0; j < times[i].size() - 1; j++){
            int start = times[i][j];
            int end = times[i][j + 1] - s;
            if(end < start){
                cout << "-1" << endll;
                return;
            }
            intervals.push_back({start, end});
        }
    }
    sort(all(intervals), [](const pll& a, const pll& b) {
        if(a.second != b.second) return a.second < b.second;
        return a.first < b.first;
    });
    dbg(intervals);

    int count = 0;
    ll cend = -1;
    for(int i = 0; i < intervals.size(); i++){
        ll start = intervals[i].first;
        ll end = intervals[i].second;
        if(start > cend){
            count++;
            cend = end;
        }
    }
    cout << count << endll;
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
