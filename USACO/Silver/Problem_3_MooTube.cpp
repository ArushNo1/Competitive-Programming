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

template<typename T>
void print(vector<T>& arr){
	cerr << "{";
	for(const T& n: arr){
		cerr << n;
	}
	cerr << "}" << endll;
}

template <class X>
void print(X& arr){
    cerr << "{";
    for(auto const& n : arr){
        cerr << n << ", ";
    }
    cerr << ")" << endll;
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


vector<vii> neighbors;
int min_relevance;
vector<bool> visited;
int num_videos;

void dfs(int node){
    visited[node] = true;

    //cerr << "dfsing " << node << ": ";
    //!
    //print(visited);

    for(auto vid : neighbors[node]){
        //cerr << "  nb " << vid.first << ":" << vid.second << endll;
        if(!visited[vid.first] && vid.second >= min_relevance){
            num_videos++;
            dfs(vid.first);
        }
    }    
}


int main()
{
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    ios_base::sync_with_stdio(0);
    
	
	open("mootube.in", "mootube.out");
    //int T = 1; cin >> T; for(int t = 0; t < T; t++) solve();
    ll n, q;
    cin >> n >> q;

    neighbors = vector<vii>(n);
    
    for(int i = 0; i < n - 1; i++){
        int a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        neighbors[a].push_back({b, c});
        neighbors[b].push_back({a, c});
    }

    /*
    for(int i = 0; i < n; i++){
        cerr << i << "to \n   ";
        for(auto& con : neighbors[i]){
            cerr << con.first << ":" << con.second << ", ";
        }
        cerr << endll;
    }
    */

    for(int i = 0; i < q; i++){
        //cerr << "qurery" << i << endll;
        visited = vector<bool>(n);
        int start_video;
        cin >> min_relevance >> start_video;
        num_videos = 0;
        dfs(start_video - 1);
        cout << num_videos << endll;
    }
}