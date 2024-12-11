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
typedef vector<bool> vb;

typedef tree<int,null_type,less<int>,rb_tree_tag,
tree_order_statistics_node_update> indexed_set;


#define endll '\n'

#define all(x) (x).begin(), (x).end()
#define MOD ll(1e9+7)
#define inf int(2e31-1)
#define INF ll(2e63-1)
#define EPS ld(1e-9)
#define dbg(x) cerr << __LINE__ << ": " << #x << "=" << x << endll;
#define print(x) cout << __LINE__ << ": " << #x << "=" << x << endll;
#define ans(x) cout << (x) << endll; return;

// File 1: /t/Templates/Debugging/vectordbg.cpp

template <typename T>
ostream& operator<<(ostream& os, const vector<T>& arr) {
    os << "[";
    for (size_t i = 0; i < arr.size(); ++i) {
        os << arr[i] << " ";
    }
    os << "]";
    return os;
}

template <typename T>
ostream& operator<<(ostream& os, const vector<vector<T>>& grid) {
    os << "[\n";
    for (const auto& row : grid) {
        os << "  " << row << "\n";
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
inline void open(string name){
    freopen((name + ".in").c_str(), "r", stdin);
	freopen((name + ".out").c_str(), "w", stdout);
}

void solve(vector<string>& grid)
{
    int x = 0, y = 0;
    int direction = -1;
    //0 = right, 1 = down, 2 = left, 3 = up

    for(int i = 0; i < grid.size(); i++){
        for(int j = 0; j < grid[i].size(); j++){
            switch(grid[i][j]){
                case '.':
                case '#':
                    break;
                case '>':
                    direction = 0;
                    break;
                case 'v':
                    direction = 1;
                    break;
                case '<':
                    direction = 2;
                    break;
                case '^':
                    direction = 3;
            }
            if(direction > -1){
                x = j;
                y = i;
                break;
            }
        }
        if(direction > -1) break;
    }
    
    vvi visited(grid.size(), vi(grid[0].size(), 0));

    int numvisited = 0;
    int numobs = 0;
    while(true){
        if(!visited[y][x]){
            visited[y][x] = true;
            numvisited++;
        }
        int nx = x, ny = y;
        switch(direction){
            case 0:
                nx ++;
                break;
            case 1: 
                ny ++;
                break;
            case 2:
                nx --;
                break;
            case 3:
                ny --;
                break;
        }
        
        if(nx < 0 || nx >= grid[0].size() || ny < 0 || ny >= grid.size()){
            break;
        } 
        else if( grid[ny][nx] == '#'){
            direction += 1;
            direction %= 4;
            x = direction == 0? x + 1 : direction == 2? x - 1 : x;
            y = direction == 1? y + 1 : direction == 3? y - 1 : y;
        }
        else{
            x = nx;
            y = ny;
        }
    }
    cout << numvisited << endll;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);  
    
    vector<string> grid;
    string s;

    while(cin >> s){
        grid.push_back(s);
    }
    
    solve(grid);
}
