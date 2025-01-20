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

void solve(int num_tc)
{
    int n;
    cin >> n;
    vi nums(n);
    fillv(nums, n);
    vi copy = nums;
    sort(all(copy));
    dbg(copy);
    if(copy[0] == copy.back()){
        cout << "YES" << endll;
        return;
    }
    if(n == 1){
        cout << "YES" << endll;
        return;
    }
    if(n == 2){
        if(nums[0] > nums[1]){
            cout << "NO" << endll;
            return;
        }
        cout << "YES" << endll;
        return;
    }
    if(nums[0] > nums[1]){
        cout << "NO" << endll;
        return;
    }
    for(int i = 1; i < n - 1; i++){
        if(nums[i] > nums[i + 1]){
            if(i >= 2 && nums[i - 2] > 0){
                dbg(i);
                cout << "NO" << endll;
                return;
            }
            int minn = min(nums[i], nums[i - 1]);
            nums[i] -= minn;
            nums[i - 1] -= minn;
        }
        if(nums[i] > nums[i + 1]){
            cout << "NO" << endll;
            return;
        }
        if(nums[i - 1] > 0){
            int minn = min(nums[i], nums[i - 1]);
            nums[i] -= minn;
            nums[i - 1] -= minn;
        }
        dbg(nums);
    }
    cout << "YES" << endll;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);  

    ll T = 1;
    cin >> T;
    for(ll t = 0; t < T; t++){
        solve(t+1);
    }
}
