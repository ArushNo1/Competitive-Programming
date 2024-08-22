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
//typedef pair<ll,ll> pll;

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

void print(multiset<int> s){
    for(auto x : s){
        cerr << x << ", ";
    }
    cerr << endll;
}

int main()
{
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    ios_base::sync_with_stdio(0);
    
	
	//open("abc.in", "abc.out");
    //int T = 1; cin >> T; for(int t = 0; t < T; t++) solve();
    int n, k;
    cin >> n >> k;
    vector<pair<ll,ll>> movies(n);
    fillv(movies, n, true);
    sort(all(movies));
    
    multiset<int> members;
    for(int i = 0; i < k; i++) members.insert(0);

    int count = 0;

    for(int movienum = 0; movienum < n; movienum++){
        auto it = members.upper_bound(movies[movienum].second);
        if(it == members.begin()) continue;
        it = prev(it);
        members.erase(it);
        members.insert(movies[movienum].first);
        count++;
        
    }

    cout << count << endll;

}
