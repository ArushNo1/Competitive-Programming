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

vector<ll> factorial(200001);
vector<ll> invFactorial(factorial.size());

long long binomial(ll n, ll k) {
    return ((factorial[n] * invFactorial[k]) % MOD * invFactorial[n - k]) % MOD;
}


void solve(int num_tc)
{
    int n, m, k;
    //n: array len, m: tuple len
    cin >> n >> m >> k;
    ll ans = 0;
    vi a(n);
    fillv(a, n);
    sort(all(a));
    for(int i = 0; i <= n - m; i++){
        int uindex = upper_bound(all(a), a[i] + k) - a.begin();
        int q = min(uindex - i - 1, n - i);
        ll c = (q < m - 1)? 0 : binomial(q, m - 1) % MOD;
        ans = (ans + c) % MOD;
    }
    cout << ans << endll;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);  

    factorial[0] = 1;
    for(int i = 1; i < factorial.size(); i++){
        factorial[i] = (factorial[i - 1] * i) % MOD;
    }
    invFactorial.back() = invMod(factorial.back());
    for(int i = factorial.size() - 2; i >= 0; i--){
        invFactorial[i] = invFactorial[i + 1] * (i + 1) % MOD;
    }
    ll T = 1;
    cin >> T;
    for(ll t = 0; t < T; t++){
        solve(t+1);
    }
}
