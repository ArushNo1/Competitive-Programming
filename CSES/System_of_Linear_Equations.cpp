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

ll invMod(ll x) {
  if (x <= 1) {
    return x;
  }
  return MOD - MOD / x * invMod(MOD % x) % MOD;
}

void solve(int num_tc)
{
    int n, m;
    cin >> n >> m;

    vector<vll> a(n, vll(m + 1));
    for(int i = 0; i < n; i++){
        fillv(a[i], m + 1);
    }

    auto fixbydivide = [&](int r){
        ll divider = invMod(a[r][r]);
        for(int c = r; c <= m; c++){
            a[r][c] = (a[r][c] * divider) % MOD;
        }
    };

    auto fixbysubtract = [&](int r, int onec){
        //the value of a[c][c] is already 1
        //so 
        ll multiplier = a[r][onec];
        for(int c = onec; c <= m; c++){
            a[r][c] = (a[r][c] - (multiplier * a[onec][c]) % MOD + MOD) % MOD;
        }
    };

    for(int c = 0; c < m; c++){
        int pivot = -1;
        for(int r = c; r < n; r++){
            if(a[r][c] != 0){
                pivot = r;
                break;
            }
        }
        if(pivot == -1) continue;
        if(pivot != c){
            swap(a[c], a[pivot]);
        }

        fixbydivide(c);
        for(int r = (c + 1) % n; r != c; r = (r + 1) % n){
            if(a[r][c] != 0){
                fixbysubtract(r, c);
            }
        }
    }
    vector<int> solution;
    for(int r = 0; r < n; r++){
        int one = false;
        for(int c = 0; c < m; c++){
            if(a[r][c] != 0){
                one = true;
            }
        }
        if(!one){
            if(a[r][m] != 0){
                cout << "-1" << endll;
                return;
            }
            else{
                solution.push_back(0);
            }
        } else {
            solution.push_back(a[r][m]);
        }
    }
    for(int i = 0; i < m; i++){
        cout << solution[i] << " ";
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
