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


#define endll "\n"

#define all(x) (x).begin(), (x).end()

#define tr(c,i) for(__typeof__((c)).begin() i = (c).begin(); i != (c).end(); i++)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())

#define MOD ll(1e9+7)
#define INF ll(2e63-1)
#define dbg(x) cerr << __LINE__ << ": " << #x << "=" << x << endll;
#define dbgl(x,l) cerr << #l << " " << l << ": " << #x << "=" << x << endll;

template <typename T>
ostream& operator<< (ostream& os, vector<T>& arr){
	os << "[";
    for(T& x : arr){
		os << x << " ";
	}
	os << "]";
    return os;
}

template <typename T, typename U>
ostream& operator<< (ostream& os, pair<T, U>& x){
    os << "(" << x.first << ", " << x.second << ")";
    return os;
}

template <typename T, typename U>
ostream& operator<< (ostream& os, vector<pair<T, U>>& arr){
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

void solve()
{

}
ll binexp(ll a, ll b){
    ll res = 1;
    while(b > 0){
        if(b % 2 == 1){
            res = (res * a) % MOD;
        }
        a = (a * a) % MOD;
        b /= 2;
    }
    return res;
}
ll modinv(ll a){
    return binexp(a, MOD - 2);
}
int main()
{
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    ios_base::sync_with_stdio(0);
	open("sumdiv");
    //int T = 1; cin >> T; for(int t = 0; t < T; t++) solve();
    
    ll a, b;
    cin >> a >> b;
    b %= MOD - 1;
    if(b == 0){
        cout << 1 << endll;
        return 0;
    }
	
    ll total = 1;
    
    for(int i = 2; i * i <= a; i++){
        ll count = 0;
        while(a % i == 0){
            count++;
            a /= i;
        }
        if(count == 0) continue;
        count *= b;
        total = (total * (binexp(i, count + 1) - 1)) % MOD;
        total = (total * (modinv(i - 1))) % MOD;
    }
    if(a > 1) {
        ll count = b;
        total = (total * (binexp(a, count + 1) - 1)) % MOD;
        total = (total * (modinv(a - 1))) % MOD;
    }
    cout << total << endll;
    
	
	
}
