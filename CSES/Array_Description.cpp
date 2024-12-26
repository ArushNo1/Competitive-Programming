#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops") 
#include <bits/stdc++.h>
using namespace std;

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
#define inf int(2e31-1)
#define INF ll(2e63-1)
#define EPS ld(1e-9)
#define dbg(x) cerr << __LINE__ << ": " << #x << "=" << x << endl;

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

void solve(int num_tc)
{
    int n, m;
    cin >> n >> m;
    vi arr(n);
    fillv(arr, n);

    if(n == 1 && arr[0] == 0){
        cout << m << endll;
        return;
    }

    vvi dp(n, vi(m + 1, 0));
    if(arr[0] == 0) {fill(all(dp[0]), 1);}
    else dp[0][arr[0]] = 1;

    for(int i = 1; i < n; i++){
        if(arr[i] != 0){
            ll j = arr[i];
            dp[i][j] = dp[i-1][j];
            if(j > 1) dp[i][j] = (dp[i][j] + dp[i-1][j-1]) % MOD;
            if(j < m) dp[i][j] = (dp[i][j] + dp[i-1][j+1]) % MOD;
        }
        else{
            for(int j = 1; j <= m; j++){
                dp[i][j] = dp[i-1][j];
                if(j > 1) dp[i][j] = (dp[i][j] + dp[i-1][j-1]) % MOD;
                if(j < m) dp[i][j] = (dp[i][j] + dp[i-1][j+1]) % MOD;
            }
        }
    }
    
    cout << accumulate(all(dp[n-1]), 0LL) % MOD << endll;
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
