#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops") 
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef vector<bool> vb;

typedef tree<int,null_type,less<int>,rb_tree_tag,
tree_order_statistics_node_update> indexed_set;



#define endll '\n'

#define all(x) (x).begin(), (x).end()
#define MOD ll(1e9+7)
#define inf int(2e31-1)
#define INF ll(2e63-1)
#define EPS ld(1e-9)
#define dbg(x) cerr << __LINE__ << ": " << #x << "=" << x << endll;
#define print(x) cout << __LINE__ << ": " << #x << "=" << x << endll;
#define ans(x) cout << (x) << endll; return;

template <typename T>
ostream& operator<< (ostream& os, const vector<T>& arr){
    os << "[";
    for(const T x : arr){
        os << x << " ";
    }
    os << "]";
    return os;
}

template <typename T, typename U>
ostream& operator<< (ostream& os, const pair<T, U>& x){
    os << "(" << x.first << ", " << x.second << ")";
    return os;
}

template <typename T, typename U>
ostream& operator<< (ostream& os, const vector<pair<T, U>>& arr){
    os << "{\n";
    for(const pair<T,U>& x : arr){
        os << "    " << x << endll;
    }
    os << "}";
    return os;
}

template <typename T, typename U>
ostream& operator<< (ostream& os, const map<T, U>& arr){
    os << "{\n";
    for(const pair<T,U>& x : arr){
        os << "    " << x << endll;
    }
    os << "}";
    return os;
}

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

int n;
int matrices[4][1001][1001];
vector<int> nums = {0, 1, 2, 3};

ll seed = 694120;
ll drand()
{
    seed = (((ll)seed * 7 + 13) % 1000000007) * 69 + 420 % 1000000;
    srand(seed);
    return seed + rand();
}

inline bool mat_mul()
{
    if(n >= 500)
    {
        for(int r = 0; r < 30000; r++)
        {
            int i = drand() % n, j = drand() % n;
            
            int res1 = 0, res2 = 0;
            for (int k = 0; k < n; ++k) 
            {
                res1 += matrices[nums[0]][i][k] * matrices[nums[1]][k][j];
                res2 += matrices[nums[2]][i][k] * matrices[nums[3]][k][j];
            }
            
            if(res1 != res2) 
            {
                return false;
            }
        }

        return true;
    }

    for (int i = 0; i < n; ++i) 
    {
        for (int j = 0; j < n; ++j) 
        {
            int res1 = 0, res2 = 0;
            for (int k = 0; k < n; ++k) 
            {
                res1 += matrices[nums[0]][i][k] * matrices[nums[1]][k][j];
                res2 += matrices[nums[2]][i][k] * matrices[nums[3]][k][j];
            }
            
            if(res1 != res2) 
            {
                return false;
            }
        }
    }
    return true;
}

void solve(int num_tc)
{
    cin >> n;

    for(int k = 0; k < 4; k++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin >> matrices[k][i][j];
            }
        }
    }

    char lets[4] = {'A', 'B', 'C', 'D'};
    do
    {
        if(mat_mul()){
            cout << lets[nums[0]] << " " << lets[nums[1]] << endll;
            cout << lets[nums[2]] << " " << lets[nums[3]] << endll;
            return;
        }
    } while(next_permutation(begin(nums), end(nums)));
    cout << "No solution." << endll;
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