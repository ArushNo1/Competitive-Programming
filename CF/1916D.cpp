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
    ll n;
    cin >> n;
    if (n == 1){
        cout << "1" << endll;
        return;
    }
    if (n == 3){
        cout << "169" << endll;
        cout << "196" << endll;
        cout << "961" << endll;
        return;
    }
    string s(n, '0');
    s[0] = '1';
    s[1] = '6';
    s[2] = '9';
    int sind = 1;
    int nind = 2;
    string dummy = "961";
    while(nind < n){
        cout << s << endll;
        swap(s[0], dummy[0]);
        swap(s[sind], dummy[1]);
        swap(s[nind], dummy[2]);
        cout << s << endll;
        swap(s[0], dummy[0]);
        swap(s[sind], dummy[1]);
        swap(s[nind], dummy[2]);
        if(nind + 2 >= n) break;
        swap(s[nind], s[nind + 2]);
        nind += 2;
        swap(s[sind], s[sind + 1]);
        sind += 1;
        
    }
    cout << "196" << string(n - 3, '0') << endll;
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
