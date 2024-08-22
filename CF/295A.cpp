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

typedef tree<int,null_type,less<int>,rb_tree_tag,
tree_order_statistics_node_update> indexed_set;


#define endll "\n"

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend() 

#define tr(c,i) for(__typeof__((c)).begin() i = (c).begin(); i != (c).end(); i++)
#define present(c,x) ((c).find(x) != (c).end())

#define cpresent(c,x) (find(all(c),x) != (c).end())

#define sz(a) ll((a).size())
#define MOD ll(1e9+7)
#define INF ll(2e63-1)
#define dbg(x) cerr << __LINE__ << ": " << #x << "=" << x << endl;


template <typename T>
void print(vector<vector<T>>& mat, ostream& os = cerr){
	for(vector<T>& arr : mat){
		for(T& x : arr){
			os << x << " ";
		}
		os << endll;
	}
}

template <typename T>
void print(vector<T>& arr, ostream& os = cerr){
	for(T& x : arr){
			os << x << " ";
	}
	os << endll;
}

template <typename T>
void print(T obj, ostream&os = cerr){
	os << obj << endll;
}


template <typename T>
inline void fillv(vector<T>& v, int n) {
    for (int i = 0; i < n; ++i) {
        std::cin >> v[i + 1];
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

inline void open(const char * fin, const char * fout)
{
    freopen(fin, "r", stdin);
    freopen(fout, "w", stdout);
}

void solve()
{

}

struct trip{
    ll first, second, third;
    trip(ll a, ll b, ll c) : first(a), second(b), third(c) {};
    trip(){
        first = 0;
        second = 0;
        third = 0;
    }
    
};
ostream& operator<<(ostream& os, const trip& t){
    return os << "l:" << t.first << ", r:" << t.second << ", d:" << t.third << endll;
}

int main()
{
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    ios_base::sync_with_stdio(0);
    
	
	//open("abc");
    //int T = 1; cin >> T; for(int t = 0; t < T; t++) solve();
    int n, m, k;
    cin >> n >> m >> k;
    vll diff(n + 3), a(n + 3);
    //a is 0-indexed;
    //diff says add diff[i] to a[i] and beyond
    fillv(a, n);
    vector<trip> opers(m + 3);
    vi operscount(m + 3);
    vi opersdiff(m + 3);
    for(int i = 1; i <= m; i++){
        cin >> opers[i].first >> opers[i].second >> opers[i].third;
    }

    for(int i = 0; i < k; i++){
        int x, y;
        cin >> x >> y;
        opersdiff[x]++;
        opersdiff[y + 1]--;
    }
    
    ll opadder = 0;
    for(int i = 0; i < m + 2; i++){
        opadder += opersdiff[i];
        operscount[i] = opadder;
    }
    for(int i = 0; i <= m; i++){
        opers[i].third *= operscount[i];
        diff[opers[i].first] += opers[i].third;
        diff[opers[i].second + 1] -= opers[i].third;
    }
    ll adder = 0;
    for(int i = 1; i <= n; i++){
        adder += diff[i];
        cout << (a[i] + adder) << " ";
    }
    
    
}
