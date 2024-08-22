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

struct ap{
    int first, second;
    ap operator+ (const ap& o){
        ap result (this->first + o.first, this->second + o.second);
        return result;
    }
    ap& operator+= (const ap& o){
        this->first += o.first;
        this->second += o.second;
        return *this;
    }
    ap(int a, int b) : first(a), second(b) {};
    bool operator< (const ap& o) const{
        if(this->first != o.first) return this->first < o.first;
        return this->second > o.second;
    }
};

vector<vector<bool>> visited;
vector<string> graph;
int n;

ap dfs(int r, int c){
    if(r < 0 || c < 0 || r >= n || c >= n || (graph[r][c] == '.')){
        return {0, 1};
    }
    if(visited[r][c]){
        return {0, 0};
    }
    visited[r][c] = true;
    ap cell = {1, 0};
    
    cell += dfs(r - 1, c);
    cell += dfs(r + 1, c);
    cell += dfs(r, c + 1);
    cell += dfs(r, c - 1);

    return cell;
}

int main()
{
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    ios_base::sync_with_stdio(0);
    
	
	open("perimeter.in", "perimeter.out");
    //int T = 1; cin >> T; for(int t = 0; t < T; t++) solve();
    cin >> n;

    visited = vector<vector<bool>>(n, vector<bool>(n));
    graph = vector<string>(n);
    fillv(graph, n);
    ap big = {0, 0};
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(graph[i][j] == '#' && !visited[i][j]){
                ap x = dfs(i, j);
                big = max(big, x);
            }
        }
    }

    cout << big.first << " " << big.second << endll;
    
}
