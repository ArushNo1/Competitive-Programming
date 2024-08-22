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
#define dbg(x) cerr << __LINE__ << ": " << #x << "=" << x << endll;


void print(vector<vector<int>>& mat, ostream& os = cerr, int jit = 0){
	for(vector<int>& arr : mat){
		for(int& x : arr){
			os << x << " ";
            if(x < 10) 
                os << " ";
            if(jit && x < 100)
                os << " ";
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

inline void open(const char * fin, const char * fout)
{
    freopen(fin, "r", stdin);
    freopen(fout, "w", stdout);
}

void solve()
{

}

int main()
{
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    ios_base::sync_with_stdio(0);
    
	
	open("lazy");
    //int T = 1; cin >> T; for(int t = 0; t < T; t++) solve();
    ll N, K;
    cin >> N >> K;
    ll n = 2 * N - 1;
    ll k = 2 * K + 1;
    vvll grid(n , vll(n));
    ii start = {0, N - 1};
    for(ll i = 0; i < N; i++){
        int r = start.first + i;
        int c = start.second - i;
        for(ll j = 0; j < N; j++){
            cin >> grid[r][c];
            r ++;
            c ++;
        }
    }
    
    vvll pref(n + 1, vll(n + 1));
    for(ll i = 0; i < n; i++){
        for(ll j = 0; j < n; j++){
            pref[i + 1][j + 1] = pref[i][j + 1] + pref[i + 1][j] - pref[i][j] + grid[i][j];
        }
    }
    
    ll m = 0;
    for(ll i = k; i < n; i++){
        for(ll j = k; j < n; j++){
            ll grass = pref[i][j] - pref[i - k][j] - pref[i][j - k] + pref[i - k][j - k]; 
            m = max(m, grass);
        }
    }

    if(K >= N) {
        cout << pref[n][n] << endll;
        return 0;   
    }

    cout << m << endll;
    
}

