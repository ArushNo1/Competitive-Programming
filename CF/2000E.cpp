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
#define print(x) cout << __LINE__ << ": " << #x << "=" << x << endll;

template <typename T>
ostream& operator<< (ostream& os, const vector<T>& arr){
	os << "[";
    for(T& x : arr){
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

template <typename T, typename U, typename c>
ostream& operator<< (ostream& os, const map<T, U, c>& arr){
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
    ll n, m, k;
    cin >> n >> m >> k;

    int w;
    cin >> w;
    vll gor(w);
    fillv(gor, w);
    sort(all(gor), std::greater<ll>());

    ll maxhor = min(k, n - k + 1);
    ll maxver = min(k, m - k + 1);

    map<ll, ll, std::greater<ll>> counts;

    ll total = 0;
    

    for(ll r = 0; r < n; r++){
        for(ll c = 0; c < m; c++){
            counts[(min(min(r, n - (r + 1)) + 1, maxhor) * min(min(c, m - (c + 1)) + 1, maxver))]++; 
        }
    }

    dbg(counts);

    bool end = false;
    int gindex = 0;
    for(const pll& p : counts){
        ll num = p.second;
        ll tsum = 0;
        while(num--){
            tsum += gor[gindex];
            ++gindex;
            if(gindex >= w){
                end = true;
                break;
            }
        }
        total += (tsum * p.first);
        if(end) break;
    }

    cout << total << endll;
    //num_subsquares * gor_height;
    




}

int main()
{
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    ios_base::sync_with_stdio(0);
	//open("abc");
    int T = 1; cin >> T; for(int t = 0; t < T; t++) solve();
    

	
	
	
}
