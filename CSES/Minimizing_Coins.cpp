#pragma GCC optimize("Ofast")
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

void print(vi& arr){
	cerr << "{";
	for(auto const& n: arr){
		cerr << n << ", ";
	}
	cerr << "}" << endll;
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
    
	
	//open("abc.in", "abc.out");
    //int T = 1; cin >> T; for(int t = 0; t < T; t++) solve();
    int n, x;
    cin >> n >> x;
    if(x == 0){
        cout << 0 << endll;
        return 0;
    }

    vi coin_values(n);
    fillv(coin_values, n);
    
    if(n == 1){
        int c = coin_values[0];
        cout << ((x % c == 0)? x / c : -1) << endll;
        return 0;
    }

    sort(all(coin_values));

    vi num_coins(x + 1, -1);
    for(auto c : coin_values){
        num_coins[c] = 1;
        if(c == x){
            cout << 1 << endll;
            return 0;
        }
    }

    for(int i = 1; i <= x; i++){
        int low = INT_MAX;
        for(auto c : coin_values){
            if(i > c){
                int z = num_coins[i - c] + 1;
                if(z != 0) low = min(low, z);
            }
            else {
                low = (i == c) ? 1 : low;
                break;
            }
        }
        if(low != INT_MAX) num_coins[i] = low;     
    }

    
    cout << num_coins[x] << endll;
}
