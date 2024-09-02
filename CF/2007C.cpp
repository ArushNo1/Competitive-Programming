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

typedef tree<ll,null_type,less<ll>,rb_tree_tag,
tree_order_statistics_node_update> indexed_set;


#define endll '\n'

#define all(x) (x).begin(), (x).end()
#define MOD ll(1e9+7)
#define INF ll(2e63-1)
#define EPS ld(1e-9)
#define dbg(x) cerr << __LINE__ << ": " << #x << "=" << x << endll;
#define print(x) cout << __LINE__ << ": " << #x << "=" << x << endll;

ll ind = -1;
template <typename T>
ostream& operator<< (ostream& os, const set<T>& arr){
    int i = 0;
	os << "[";
    for(const T x : arr){
        if(i == ind) os << ">";
		os << x << " ";
        ++i;
	}
	os << "]";
    return os;
}
template <typename T>
ostream& operator<< (ostream& os, const vector<T>& arr){
    int i = 0;
	os << "[";
    for(const T x : arr){
        if(i == ind) os << ">";
		os << x << " ";
        ++i;
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

ll comp(ll a, ll b){
    if(abs(a) > abs(b)){
        return b;
    }
    else{
        return a;
    }
}

ll range(set<ll>& s){
    return *s.rbegin() - *s.begin();
}

ll nmod(ll a, ll b){
    return -(-a % -b);
}

void solve(int num_tc)
{
    ll n, a, b;
    cin >> n >> a >> b;
    ll g = gcd(a, b);
    if(a > b){
        swap(a, b);
    }
    set<ll> nums;
    for(int i = 0; i < n; i++){
        ll t;
        cin >> t;
        t %= g;
        nums.insert(t);
    }
    a %= g;
    b %= g;
    dbg(a);
    dbg(g);
    dbg(b);
    
    

    vll arr(all(nums));
    n = arr.size();
    ll range = arr[n - 1] - arr[0];
    dbg(range);
    for(int i = 0; i < n; i++){
        arr.push_back((arr[i] + b));
        range = min(range, abs(arr.back() - arr[i + 1]));
        
        dbg(arr);
        dbg(range);
    }
    cout << range << endll;
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
