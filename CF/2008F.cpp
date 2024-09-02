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
#define EPS ld(1e-9)
#define dbg(x) cerr << __LINE__ << ": " << #x << "=" << x << endll;
#define print(x) cout << __LINE__ << ": " << #x << "=" << x << endll;
#define ans(x) cout << x << endll; return;

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


namespace math {
    // time = O(log(N))
    ll binExp(ll a, ll b) {
    if (b == 0)
        return 1;

    ll res = binExp(a, b / 2) % MOD;
    if (b & 1) {
        return (a * ((res * res) % MOD)) % MOD;
    } else
        return (res * res) % MOD;
    }

    // Time = O(log(N))
    ll invMod(ll x) {
    if (x <= 1) {
        return x;
    }
    return MOD - MOD / x * invMod(MOD % x) % MOD;
    }

    void sieve(vector<bool>& is_prime, ll n)
    {
        is_prime[0] = is_prime[1] = false;
        for (ll i = 2; i <= n; i++) {
            if (is_prime[i] && (ll)i * i <= n) {
                for (ll j = i * i; j <= n; j += i)
                    is_prime[j] = false;
            }
        }
    }

    bool isPrime(ll x) {
        for (ll d = 2; d * d <= x; d++) {
            if (x % d == 0)
                return false;
        }
        return x >= 2;
    }

    vector<ll> factors(ll n, vector<ll> &primes) {
        vector<ll> factorization;
        for (ll d : primes) {
            if (d * d > n)
                break;
            while (n % d == 0) {
                factorization.push_back(d);
                n /= d;
            }
        }
        if (n > 1)
            factorization.push_back(n);
        return factorization;
    }
    map<ll, ll> primeFactorization(ll num){
        map<ll, ll> factors;
        for(ll i = 2; i * i <= num; i++){
            while(num % i == 0){
                factors[i]++;
                num /= i;
            }
        }
        if(num > 1) {
            factors[num] = 1;
        }
        return factors;
    }

}; // namespace math


void solve(int num_tc)
{
    int n;
    cin >> n;
    map<ll, ll> counts;
    for(int i = 0; i < n; i++){
        ll t;
        cin >> t;
        counts[t]++;
    }
    //dbg(counts);
    ll totalways = 0;
    ll div2 = math::invMod(2);
    map<ll, ll> prods;
    vector<pll> parr(all(counts));
    int N = parr.size();
    vector<ll> prefs(N + 1);
    vector<ll> pref2(N + 1);
    
    //dbg(counts);


    ll prob = 0;

    //prefs[i] = sum of i ... N
    for(int i = N - 1; i >= 0; i--){
        prefs[i] = (prefs[i + 1] + (parr[i].first * parr[i].second) % MOD ) % MOD;
        pref2[i] = (pref2[i + 1] + (parr[i].second) % MOD ) % MOD;
    }

    //dbg(prefs);
    //dbg(pref2);
    //dbg(parr);

    ll denom = 0;

    for(int i = 0; i < N; i++){
        ll f = (parr[i].first * parr[i].second) % MOD;
        prob = (prob + (f * prefs[i + 1]) % MOD) % MOD;
        ll value = (((((f * (parr[i].second - 1)) % MOD) * parr[i].first) % MOD) * div2) % MOD;
        prob = (prob + value) % MOD;

        ll g = parr[i].second;
        //dbg(g);
        denom = (denom + (((g * (g - 1)) % MOD) * div2) % MOD) % MOD;
        denom = (denom + (g * pref2[i + 1]) % MOD) % MOD;
        //dbg(prob);
        //dbg(denom);
    }

    //dbg(denom);
    //dbg(prob);
    prob = (prob * math::invMod(denom)) % MOD;
    ans(prob);
    // for(int i = 0; i < parr.size(); i++){
    //     pll f = parr[i];
    //     //f.second * sum of s.second;
    //     for(pll s : counts){
    //         ll x = (f.first * s.first) % MOD;
    //         ll q = ((f.second * (s.second - (f.first == s.first))) % MOD * div2) % MOD;
    //         totalways = (totalways + q) % MOD;
    //         ll& p = prods[x];
    //         p = (p + q) % MOD;
    //     }
    // }
    //dbg(prods);
    for(pll i : prods){
        ll x = (i.first * i.second) % MOD;
        prob = (prob + x) % MOD;
    }
    prob = (prob * math::invMod(totalways)) % MOD;
    cout << prob << endll;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);  

    ll T = 1;
    cin >> T;
    for(ll t = 0; t < T; t++){
        solve(t+1);
    }
}
