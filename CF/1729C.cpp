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
    string s;
    cin >> s;
    char b = s[0];
    char e = s.back();
    bool flip = false;
    s.erase(s.begin());
    s.pop_back();

    if(b > e){
        swap(b, e);
        flip = true;
    }

    vector<int> ans;
    
    if(flip) ans.push_back(s.size() + 1);
    else ans.push_back(0);
    vector<pair<char, int>> v;
    for(int i = 0; i < s.size(); i++){
        v.push_back({s[i], i + 1});
    }
    sort(all(v));
    int i = lower_bound(all(v), make_pair(b, 0)) - v.begin();
    for(; i < v.size(); i++){
        if(v[i].first > e) break;
        ans.push_back(v[i].second);
    }
    if(!flip) ans.push_back(s.size() + 1);
    else ans.push_back(0);
    if(flip){
        reverse(all(ans));
    }
    cout << abs(b - e) << " " << ans.size() << endll;
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] + 1 << " ";
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
