#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops") 

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>


using namespace __gnu_pbds;
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii; 
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
#define INF ll(2e63-1)
#define dbg(x) cerr << __LINE__ << ": " << #x << "=" << x << endll;
#define print(x) cout << __LINE__ << ": " << #x << "=" << x << endll;

template <typename T>
ostream& operator<< (ostream& os, const vector<T>& arr){
	os << "[";
    for(const T x : arr){
		os << x << " ";
	}
	os << "]";
    return os;
}

template<>
ostream& operator<< (ostream& os, const vector<vector<int>>& arr){
	os << "[";
    for(const vector<int>& x : arr){
		os << x << " " << endll;
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

void solve(int num_tc)
{
    int n;
    cin >> n;
    int total = n * (n + 1) / 2;
    if(total & 1){
        cout << 0 << endll;
        return;
    }
    int desiredsum = total / 2;
    //dp[i][j] = number of ways to create sum i with numbers 1-j
    vvi dp(n, vi(desiredsum + 1));
    
    dp[0][0] = 1;

    for(int i = 1; i < n; i++){
        for(int j = 0; j <= desiredsum; j++){
            dp[i][j] += dp[i - 1][j];
            if(j >= i) dp[i][j] += dp[i - 1][j - i];
            dp[i][j] %= MOD;
        }
    }


    cout << dp.back().back() << endll;

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);  

    ll T = 1;
    //cin >> T;
    for(ll t = 0; t < T; t++){
        solve(t+1);
    }
}

/*







[1 0 0 0 0 0 0 0 ] 
[1 1 0 0 0 0 0 0 ] 
[1 2 1 0 0 0 0 0 ] 
[1 3 3 1 0 0 0 0 ] 
[1 4 6 4 1 0 0 0 ] 
[1 5 10 10 5 1 0 0 ] 
[1 6 15 20 15 6 1 0 ] 
[1 7 21 35 35 21 7 1 ] 
[1 8 28 56 70 56 28 8 ] 
[1 8 36 84 126 126 84 36 ] 
[50 8 36 120 210 252 210 120 ] 
[50 57 36 120 330 462 462 330 ] 
[100 57 85 120 330 792 924 792 ] 
[100 157 85 169 330 792 1716 1716 ] 
[100 314 185 169 379 792 1716 3432 ] 





*/