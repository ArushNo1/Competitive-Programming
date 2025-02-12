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

ostream& operator<<(ostream& os, array<int, 3> arr){
    os << "{" << arr[0] << " " << arr[1] << " " << arr[2] << "}";
    return os;
}

ostream& operator<<(ostream& os, queue<array<int, 3>>& arr){
    queue<array<int, 3>> temp = arr;
    os << "[\n";
    while(!temp.empty()){
        os << "    " << temp.front() << endll;
        temp.pop();
    }
    os << "]";
    return os;
}

//comment to enable debugging
#define dbg(x)

#ifndef dbg
#define dbg(x) cerr << __LINE__ << ": " << #x << "=" << x << endl;
//edit for specific DS
#include "cp-templates/Debugging/alldebug.h"
#endif

vector<int> dx = {1, 0, -1 , 0};
vector<int> dy = {0, 1, 0, -1};
string dir = "DRUL";
vector<string> grid;
vvi dist;

string moves = "";
bool found = false;
void dfs(int r, int c, int d) {
    if(found) return;    
    if(r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size()) {
        found = true;
        return;
    }
    for(int i = 0; i < 4; i++) {
        int nr = r + dx[i];
        int nc = c + dy[i];    
        if(nr < 0 || nr >= grid.size() || nc < 0 || nc >= grid[0].size()) {
            if(r == 0 || r == grid.size()-1 || c == 0 || c == grid[0].size()-1) {
                found = true;
                moves += dir[i];
                return;
            }
            continue;
        }        
        if(grid[nr][nc] == '#' || dist[nr][nc] <= d + 1) continue;
        int temp = dist[nr][nc];
        dist[nr][nc] = -1;  
        moves += dir[i];
        dfs(nr, nc, d + 1);
        if(found) return;
        moves.pop_back();
        dist[nr][nc] = temp;
    }
}

void solve(int num_tc)
{
    int n, m;
    cin >> n >> m;
    grid.resize(n);
    ii person;
    vector<ii> monsters;
    for(int i= 0; i < n; i++){
        cin >> grid[i];
        for(int j = 0; j < m; j++){
            if(grid[i][j] == 'M'){
                monsters.push_back({i, j});
            }
            else if(grid[i][j] == 'A'){
                person = {i, j};
            }
        }
    }
        
    dist = vvi(n, vi(m, inf));
    queue<array<int, 3>> q;
    for(int i = 0; i < monsters.size(); i++){
        q.push({monsters[i].first, monsters[i].second, 0});
        dist[monsters[i].first][monsters[i].second] = 0;
    }

    while(!q.empty()){
        int x = q.front()[0];
        int y = q.front()[1];
        int d = q.front()[2];
        q.pop();
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m || dist[nx][ny] <= d + 1){
                continue;
            }
            if(grid[nx][ny] == '#'){
                continue;
            }
            dist[nx][ny] = d + 1;
            q.push({nx, ny, d + 1});
        }
    }

    dfs(person.first, person.second, 0);
    if(found){
        cout << "YES" << endll;
        moves.pop_back();
        cout << moves.length() << endll;
        cout << moves << endll;
    }
    else{
        cout << "NO" << endll;
    }
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);  

    ll T = 1;
    //cin >> T;
    for(ll t = 0; t < T; t++){
        solve(t+1);
    }
}
