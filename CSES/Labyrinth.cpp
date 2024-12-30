#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops") 
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef long long ll;
typedef vector<ll> vll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef vector<bool> vb;

#define endll '\n'

#define all(x) (x).begin(), (x).end()
#define MOD ll(1e9+7)
#define inf int(2e31-1)
#define INF ll(2e63-1)
#define EPS ld(1e-9)
#define dbg(x) cerr << __LINE__ << ": " << #x << "=" << x << endl;

template <typename T>
ostream& operator<< (ostream& os, const vector<T>& arr){
	os << "[";
    for(const T x : arr){
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

struct node{
    int r, c;
};

vi dx = {0, 0, 1, -1};
vi dy = {1, -1, 0, 0};
vi chars = {'R', 'L', 'D', 'U'};

void solve(int num_tc)
{
    int n, m;
    cin >> n >> m;
    int startr, startc, endr, endc;
    vector<string> grid(n);
    for(int i = 0; i < n; i++){
        cin >> grid[i];
        for(int j = 0; j < m; j++){
            if(grid[i][j] == 'A'){
                startr = i;
                startc = j;
            }
            else if(grid[i][j] == 'B'){
                endr = i;
                endc = j;
            }
        }
    }
    vector<string> parent(n, string(m, ' '));
    parent[startr][startc] = '*';
    queue<node> bfs;
    bfs.push({startr, startc});
    while(!bfs.empty()){
        node u = bfs.front();
        bfs.pop();
        if(u.r == endr && u.c == endc){
            cout << "YES" << endll;
            string path;
            while(u.r != startr || u.c != startc){
                int r = u.r, c = u.c;
                int pr = parent[r][c] - '0';
                path += chars[pr];
                u.r -= dx[pr];
                u.c -= dy[pr];
            }
            reverse(all(path));
            cout << path.size() << endll;
            cout << path << endll;
            return;
        }
        for(int i = 0; i < 4; i++){
            int r = u.r + dx[i], c = u.c + dy[i];
            if(r >= 0 && r < n && c >= 0 && c < m && grid[r][c] != '#' && parent[r][c] == ' '){
                parent[r][c] = i + '0';
                bfs.push({r, c});
            }
        }
    }
    cout << "NO" << endll;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);  

    ll T = 1;
    //cin >> T;
    for(ll t = 0; t < T; t++){
        solve(t+1);
    }
}
