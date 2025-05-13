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

void phi_1_to_n(ll n, vector<ll>& phi) {
    phi[0] = 0LL;
    phi[1] = 1LL;
    for (ll i = 2; i <= n; i++)
        phi[i] = i - 1;

    for (ll i = 2; i <= n; i++)
        for (ll j = 2 * i; j <= n; j += i)
              phi[j] -= phi[i];
}
ll bound = 1e5;
vll phivals(bound + 3);
vector<ll> sumphi(bound + 3);
    
    

void solve(int num_tc)
{
    
    ll n;
    cin >> n;

    ll p = -1;
    p = std::lower_bound(all(sumphi), n) - sumphi.begin() + 1;
    dbg(p);
    

    ll num = sumphi[p - 2];
    ll diff = n - num;
    dbg(phivals[p + 1]);
    ll altdif = phivals[p + 1] - diff+1;
    dbg(diff);
    dbg(altdif);

    bool inv = false;
    if(altdif < diff){
        diff = altdif;
        for(ll x = p - 1; x >= 1; x--){
        if(__gcd(x, p) == 1){
            diff--;
            if(diff == 0){
                cout << x << " " << p-x << endll;
                return;
            }
        }
    }
    }
    for(ll x = 1; x < p; x++){
        if(__gcd(x, p) == 1){
            diff--;
            if(diff == 0){
                cout << x << " " << p-x << endll;
                return;
            }
        }
    }
    

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);  

    phi_1_to_n(bound + 2, phivals);
    phivals.erase(phivals.begin());
    sumphi[0] = 0;
    for(int i = 1; i < bound + 2; i++){
        sumphi[i] = sumphi[i-1] + phivals[i];
    }
    
    ll T = 1;
    cin >> T;
    for(ll t = 0; t < T; t++){
        solve(t+1);
    }
}
