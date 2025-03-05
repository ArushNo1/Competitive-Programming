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

vi out;
vi cc;
vi depth;
vi ans;

void dfs(int node, int d){
    if(depth[node] != -1){
        if(ans[node] != -1){
            dbg(node);
            dbg(d);
            dbg(ans[node]);
            dbg(cc);
            cc.push_back(node);
            reverse(all(cc));
            for(int i = 1; i < cc.size(); i++){
                ans[cc[i]] = ans[cc[i-1]] + 1;
            }
            //exit(0);
            return;
        }
        //do processing;
        int cycsize = d - depth[node];
        d = depth[node];
        int nb = node;
        for(int i = 0; i < cycsize; i++){
            ans[nb] = cycsize;
            nb = out[nb];
        }
        for(int i = 0; i < d; i++){
            ans[cc[i]] = d - i + cycsize;
        }
        return;
    }
    cc.push_back(node);
    depth[node] = d;
    dfs(out[node], d + 1);
}

void solve(int num_tc)
{
    int n;
    cin >> n;
    out.resize(n);
    depth.resize(n, -1);
    ans.resize(n, -1);
    for(int i = 0; i < n ;i++){
        cin >> out[i];
        out[i]--;
    }

    for(int i = 0; i < n;i++){
        if(depth[i] != -1){
            continue;
        }
        dbg(i);
        dfs(i, 0);
        cc.clear();
    }
    dbg(depth);
    dbg(ans);
    for(auto j : ans){
        cout << j << " ";
    }
    cout << endll;
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
