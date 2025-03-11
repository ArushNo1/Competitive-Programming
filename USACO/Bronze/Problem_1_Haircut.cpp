#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops") 
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

typedef tree<long long,null_type,greater_equal<long long>,rb_tree_tag,
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

void solve(int num_tc)
{
    int n;
    cin >> n;
    vll hair(n);
    for(int i = 0; i < n; i++){
        cin >> hair[i];
    }
    indexed_set st;
    vll invcaused(n + 1, 0);
    for(int i = 0; i < n; i++){
        //an inversion no longer exists when the larger element is trimmed
        //down to the smaller one
        ll ninv = st.order_of_key(hair[i]);
        st.insert(hair[i]);
        invcaused[hair[i]] += ninv;
    }
    //if j removes an inversion, j - 1 will too
    for(int i = n - 1; i >= 0; i--){
        invcaused[i] += invcaused[i + 1];
    }
    for(int i = 0; i < n; i++){
        //total inversions minus the ones saved when cutting hair to i
        cout << invcaused[0] - invcaused[i] << endll;
    }
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);  
    dbg("turn off debugging");
    open("haircut");
    ll T = 1;
    //cin >> T;
    for(ll t = 0; t < T; t++){
        solve(t+1);
    }
}
