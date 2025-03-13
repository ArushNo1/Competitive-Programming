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
//!#define dbg(x)

#ifndef dbg
#define dbg(x) cerr << __LINE__ << ": " << #x << "=" << x << endl;
//edit for specific DS
#include "cp-templates/Debugging/alldebug.h"
#endif

void solve(int num_tc)
{
    int n, q;
    cin >> n >> q;
    vi perm(n);
    for(int i= 0; i < n; i++){
        cin >> perm[i];
        perm[i]--;
    }
    string s;
    cin >> s;

    vi diff(n + 1);
    for(int i = 0; i < n; i++){
        if(i == perm[i]) continue;
        if(i < perm[i]){
            diff[i]++;
            diff[perm[i] + 1]--;
        }
        else{
            diff[perm[i]]++;
            diff[i + 1]--;
        }
    }

    int sum = 0;
    vi reqopen(n);
    for(int i = 1; i <= n; i++){
        sum += diff[i];
        reqopen[i] = sum;
    }
    dbg(reqopen);

    //each place where elm i and i + 1 are not connected
    set<int> breaks;
    set<int> badbreak;
    for(int i = 0; i < n - 1; i++){
        if(s[i] == 'L' && s[i + 1] == 'R'){
            breaks.insert(i);
            if(reqopen[i]){
                badbreak.insert(i);
            }
        }
    }
    dbg(breaks);
    dbg(badbreak);
    //i and p[i] must be connected: add that interval in
    //everywhere where the pref is 1, there must be no break

    for(int i = 0; i < q; i++){
        int x;
        cin >> x;
        x--;
        if(s[i] == 'L' && s[i + 1] == 'L'){
            continue;
        }
        if(s[i] == 'L' && s[i + 1] == 'R'){
            breaks.erase(i);
            //badbreak
        }
    }
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
