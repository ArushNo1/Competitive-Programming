#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops") 
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

typedef tree<int,null_type,less<int>,rb_tree_tag,
tree_order_statistics_node_update> indexed_set;

typedef vector<long long> vi;
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

struct hasher{
    size_t operator()(const ll& x) const{
        return hash<ll>()(x) ^ 0x234fdfbf3c2a1e5f;
    }
};

void buildsums(const vi& arr, vi& sums){
    sums.reserve(1 << arr.size());
    sums.push_back(0);
    for(int i = 0; i < arr.size(); i++){
        int sz = sums.size();
        for(int j = 0; j < sz; j++){
            sums.push_back(sums[j] + arr[i]);
        }
    }
    sort(all(sums));
}
void solve(int num_tc)
{
    ll n;
    cin >> n;
    ll x;
    cin >> x;
    vi left(n / 2);
    for(int i = 0; i < n / 2; i++){
        cin >> left[i];
    }
    vi right(n - n / 2);
    for(int i = 0; i < n - n / 2; i++){
        cin >> right[i];
    }
    ll sum = accumulate(all(left), 0ll) + accumulate(all(right), 0ll);
    if(sum < x){
        cout << 0 << endll;
        return;
    }
    vi leftsums;
    buildsums(left, leftsums);
    vi rightsums;
    buildsums(right, rightsums);
    sort(all(leftsums));
    
    ll ans = 0;
    for(auto rsum : rightsums){
        auto range = equal_range(all(leftsums), x - rsum);
        ans += range.second - range.first;
    }
    cout << ans << endll;
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
