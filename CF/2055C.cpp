#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops") 
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

typedef tree<int,null_type,less<int>,rb_tree_tag,
tree_order_statistics_node_update> indexed_set;

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
#define inf int(1e9+1)
#define INF ll(1e18+1)
#define EPS ld(1e-9)

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

//comment to enable debugging
#define dbg(x)

#ifndef dbg
#define dbg(x) cerr << __LINE__ << ": " << #x << "=" << x << endl;
//edit for specific DS
#include <alldebug.h>
#endif

void solve(int num_tc)
{
    int n, m;
    cin >> n >> m;
    string path;
    cin >> path;
    vector<vll> grid(n, vll(m, 0));
    vll rowholes (n, 0);
    vll colholes (m, 0);
    vll rowsum(n, 0);
    vll colsum(m, 0);
    int x = 0, y = 0;
    rowholes[x]++, colholes[y]++;
    for(char c : path){
        if(c == 'D'){
            x = (x + 1);
        }
        if(c == 'R'){
            y = (y + 1);
        }
        rowholes[x]++;
        colholes[y]++;
    }
    dbg(rowholes);
    dbg(colholes);
    for(int r = 0; r < n; r++){
        for(int c = 0; c < m; c++){
            cin >> grid[r][c];
            rowsum[r] += grid[r][c];
            colsum[c] += grid[r][c];
        }
    }
    x = y = 0;
    for(char c : path){
        if(rowholes[x] == 1){
            grid[x][y] = -rowsum[x];
            colsum[y] -= rowsum[x];
            rowsum[x] = 0;
            rowholes[x]--;
            colholes[y]--;
        }
        else if(colholes[y] == 1){
            grid[x][y] = -colsum[y];
            rowsum[x] -= colsum[y];
            colsum[y] = 0;
            rowholes[x]--;
            colholes[y]--;
        }
        dbg(x);
        dbg(y);
        dbg(grid[x][y]);
        if(c == 'D'){
            x = (x + 1);
        }
        if(c == 'R'){
            y = (y + 1);
        }
    }
    if(rowholes[x] == 1){
        grid[x][y] = -rowsum[x];
        colsum[y] -= rowsum[x];
        rowsum[x] = 0;
        rowholes[x]--;
        colholes[y]--;
    }
    else if(colholes[y] == 1){
        grid[x][y] = -colsum[y];
        rowsum[x] -= colsum[y];
        colsum[y] = 0;
        rowholes[x]--;
        colholes[y]--;
    }
    for(int r = 0; r < n; r++){
        for(int c = 0; c < m; c++){
            cout << grid[r][c] << " ";
        }
        cout << endll;
    }
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);  

    ll T = 1;
    cin >> T;
    for(ll t = 0; t < T; t++){
        solve(t+1);
    }
}
