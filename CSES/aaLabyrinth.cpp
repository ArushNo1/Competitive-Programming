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

bool found = false;
string sol((int)1e6, '\u0000');
int n, m;
vector<string> graph;
vector<vector<bool>> visited;

void printvisited(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cerr << visited[i][j];
        }
        cerr << endll;
    }
}

struct searchnode{
    int r, c, len;
    string path;
    char last, getchar;
    searchnode(int _r, int _c, string _path, int _len){
        r = _r;
        c = _c;
        path = _path;
        len = _len;
        last = path[len - 1];
        visited[r][c] = true;
        getchar = graph[r][c];
    }
    vector<searchnode> neighbors(){
        vector<searchnode> nb;
        if(len > sol.length()){
            return nb;
        }
        //cerr << "neightboars of " << r << ", " << c << endll;
        if(r > 0 && !visited[r - 1][c] && graph[r - 1][c] != '#'){
            nb.push_back(searchnode(r - 1, c, (path + "U"), len + 1));
            //cerr << "added node U" << endll;
        }
        if(c > 0 && !visited[r][c - 1] && graph[r][c - 1] != '#'){
            nb.push_back(searchnode(r, c - 1, (path + "L"), len + 1));
            //cerr << "added node L" << endll;            
        }
        if(r < (n - 1) && !visited[r + 1][c] && graph[r + 1][c] != '#'){
            nb.push_back(searchnode(r + 1, c, (path + "D"), len + 1));
            //cerr << "added node D" << endll;
        }
        if(c < (m - 1) && !visited[r][c + 1] && graph[r][c + 1] != '#'){
            nb.push_back(searchnode(r, c + 1, (path + "R"), len + 1));
            //cerr << "added node R" << endll;
        }
        return nb;
    }
    
};

ostream& operator<<(ostream& os, const searchnode& s){
    return (os << "(" << s.r << ", " << s.c << "): " << s.path);
}

void bfs(int r, int c){
    queue<searchnode> x;
    x.push(searchnode(r, c, "", 0));
    while(!x.empty()){
        searchnode cur = x.front();
        //cerr << cur << endll;
        x.pop();
        char g = cur.getchar;
        if(g == 'B'){
            if(sol.length() > cur.len){
                sol = cur.path;
            }
        }
        if(g != '#'){
            vector<searchnode> nb = cur.neighbors();
            for(auto const& s : nb){
                x.push(s);
            }
        }
    }
}

int main()
{
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    ios_base::sync_with_stdio(0);
    
    
    //open("abc.in", "abc.out");
    //int T = 1; cin >> T; for(int t = 0; t < T; t++) solve();
    cin >> n >> m;
    graph = vector<string>(n);
    visited = vector<vector<bool>>(n, vector<bool>(m));

    for(int i = 0; i < n; i++){
        cin >> graph[i];
    }

    for(int r = 0; r < n; r++){
        for(int c = 0; c < m; c++){
            if(graph[r][c] == 'A'){
                //cerr << "dfsing:  " << r << ", " << c << endll;
                bfs(r, c);
                //printvisited();
                if(sol.length() < 1e6){
                    cout << "YES" << endll;
                    cout << sol.length() << endll;
                    cout << sol << endll;
                }
                else{
                    cout << "NO" << endll;
                }
                return 0;
            }
        }
    }

    cout << sol << endll;

}
