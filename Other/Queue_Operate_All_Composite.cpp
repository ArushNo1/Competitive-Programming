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

#define MOD ll(998244353)
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


ll binexp(ll a, ll b)
{
    b %= MOD - 1;
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

ll mult = 1;
ll add = 0;
deque<pll> fs;

inline void dbgf(){
    dbg(mult);
    dbg(add);
    for(pll f : fs){
        dbg(f);
    }
}

int main()
{
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    ios_base::sync_with_stdio(0);
	//open("abc");
    //int T = 1; cin >> T; for(int t = 0; t < T; t++) solve();
    
    int n;
    cin >> n;
    
	for(int i = 0; i < n; i++){
        int t;
        cin >> t;
        if(t == 0) {
            ll a, b;
            cin >> a >> b;
            mult = (mult * a) % MOD;
            add = ((add * a) % MOD + b) % MOD;
            fs.push_back(make_pair(a, b));
        } else if(t == 1) {
            pll f0 = fs.front();
            fs.pop_front();
            mult = (mult * modinv(f0.first)) % MOD;
            add -= (mult * f0.second) % MOD;
            if(add < 0) add += MOD;
        } else {
            int x;
            cin >> x;
            cout << ((x * mult) % MOD + add) % MOD << endll;
            
        }
    }
	
	
}