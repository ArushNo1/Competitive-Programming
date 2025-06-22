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

int getkthdigit(int x, int k) {
    while(k--) {
        x /= 10;
    }
    return x % 10;
}

void bruteforcer(int num_tc)
{
    string l;
    string r;
    cin >> l >> r;
    int n = l.size();
    int ans = 0;
    int i = 0;
    for(; i < n; i++){
        if(l[i] != r[i]){
            break;
        }
        ans += 2;
    }
    if(i == n){
        cout << ans << endll;
        return;
    }
    if(r[i] - l[i] > 1){
        cout << ans << endll;
        return;
    }
    i++;
    for(; i < n; i++){
        int ldig = l[i] - '0';
        int rdig = r[i] - '0';
        if(ldig == 9 && rdig == 0){
            ans++;
        }
        else break;
    }
    cout << ans + 1 << endll;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);  
    dbg("turn off debugging");
    ll T = 1;
    cin >> T;
    for(ll t = 0; t < T; t++){
        bruteforcer(t+1);
    }
}
