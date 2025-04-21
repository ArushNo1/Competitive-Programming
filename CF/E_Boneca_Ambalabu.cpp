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
    map<ll, ll> score;
    int n;
    cin >> n;
    vector<ll> a(n);
    vector<ll> bitcounts(31);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    ll mask = 1;
    for(int i = 0; i < 31; i++){
        for(int j = 0; j < n; j++){
            if(a[j] & mask){
                bitcounts[i]++;
            }
        }
        mask <<= 1;
    }
    dbg(bitcounts);
    vector<array<ll, 2>> bitscores(31);
    //0 if that bit is not set, 1 if it is;
    for(int i = 0; i < 31; i++){
        bitscores[i][0] = (1 << i) * bitcounts[i];
        bitscores[i][1] = (1 << i) * (n - bitcounts[i]);
    }
    vector<ll> scores(n);
    for(int i = 0; i < n; i++){
        int val = a[i];
        for(int j = 0; j < 31; j++){
            if(val & (1 << j)){
                scores[i] += bitscores[j][1];
            }
            else{
                scores[i] += bitscores[j][0];
            }
        }
    }
    sort(all(scores), greater<ll>());
    cout << scores[0] << endll;
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
