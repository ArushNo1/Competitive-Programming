#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops") 
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef long long ll;
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
// File 1: /t/Math/Modular_Inverse.cpp

ll invMod(ll x) {
  if (x <= 1) {
    return x;
  }
  return MOD - MOD / x * invMod(MOD % x) % MOD;
}
// File 1: /t/Math/Binomial_Coefficients.cpp

ll binomial(ll n, ll k) {
	vector<vector<ll>> dp(n + 1, vector<ll>(k + 1, 0));
	for (ll i = 0; i <= n; i++) {
		dp[i][0] = 1;
		if (i <= k) { dp[i][i] = 1; }
	}
	for (ll i = 0; i <= n; i++) {
		for (ll j = 1; j <= min(i, k); j++) {
			if (i != j) {  
				dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % MOD;
			}
		}
    }
	return dp[n][k];  
}

ll exactBinomial(ll n, ll k) {
    if (k > n - k) { k = n - k; }
	long long ret = 1;
	for (int i = 0; i < k; i++) {
        ll val = ((n - i) * (invMod(i + 1) % MOD)) % MOD;
		ret = (ret * val) % MOD;
	}
	return ret;
}


void solve(int num_tc)
{
    int n, k;
    cin >> k >> n;
    cout << exactBinomial(n + k - 1, k - 1) << endll;
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
