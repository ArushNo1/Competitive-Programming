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
#define maxeq(a, b) a = max<decltype(a)>(a, b)
#define mineq(a, b) a = min<decltype(a)>(a, b)

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
template <typename T, typename U>
inline void fillv(vector<pair<T, U>>& v, int n, bool inv = false){
	if(inv){
		for(int i = 0 ; i < n; ++i){
			cin >> v[i].second >> v[i].first;
		}
		return;
	}
	for (int i = 0; i < n; ++i) {
        cin >> v[i].first >> v[i].second;
    }
	return;
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
#include <alldebug.h>
#endif

struct mat{
    vector<vector<ll>> a;
    mat(){
        a = {
            {1, 1, 1, 1, 1, 1},
            {1, 0, 0, 0, 0, 0},
            {0, 1, 0, 0, 0, 0},
            {0, 0, 1, 0, 0, 0},
            {0, 0, 0, 1, 0, 0},
            {0, 0, 0, 0, 1, 0},
        };
    }
    mat operator*(const mat& o){
        mat res;
        for(int i = 0; i < 6; i++){
            for(int j = 0; j < 6; j++){
                res.a[i][j] = 0;
                for(int k = 0; k < 6; k++){
                    res.a[i][j] += a[i][k] * o.a[k][j];
                    res.a[i][j] %= MOD;
                }
            }
        }
        return res;
    }
    mat(int i){
        a = {
            {1, 0, 0, 0, 0, 0},
            {0, 1, 0, 0, 0, 0},
            {0, 0, 1, 0, 0, 0},
            {0, 0, 0, 1, 0, 0},
            {0, 0, 0, 0, 1, 0},
            {0, 0, 0, 0, 0, 1},
        };
    }
};

mat binExp(mat a, ll b){
    if(b == 0)
        return mat(1);
    mat res = binExp(a, b / 2);
    if(b & 1){
        return res * res * a;
    }else
        return res * res;
}

void solve(int num_tc)
{
    ll n;
    cin >> n;
    if(n <= 5){
        cout << (1 << (n - 1)) << endll;
        return;
    }
    mat a;
    mat b = binExp(a, n - 5);

    ll sum = 0;
    vll v = {16, 8, 4, 2, 1, 1};
    for(int i = 0; i < 6; i++){
        sum += b.a[0][i] * v[i];
        sum %= MOD;
    }
    cout << sum << endll;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);  

    ll T = 1;
    //cin >> T;
    for(ll t = 0; t < T; t++){
        solve(t+1);
    }
}
