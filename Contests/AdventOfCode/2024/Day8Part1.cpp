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
#define dbg(x) cerr << __LINE__ << ": " << #x << "=" << x << endl;
#define print(x) cout << __LINE__ << ": " << #x << "=" << x << endll;
#define ans(x) cout << (x) << endll; return;

// File 1: /t/Templates/Debugging/vectordbg.cpp

template <typename T, typename U>
ostream& operator<< (ostream& os, const pair<T, U>& x){
    os << "(" << x.first << ", " << x.second << ")";
    return os;
}


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

// File 1: /t/Debugging/mapdbg.cpp



template <typename T, typename U>
ostream& operator<< (ostream& os, const map<T, U>& arr){
	os << "{\n";
    for(const pair<T,U>& x : arr){
		os << "    " << x << endll;
	}
	os << "}";
    return os;
}

template <typename T, typename U>
ostream& operator<< (ostream& os, const unordered_map<T, U>& arr){
    os << "{\n";
    for(const pair<T,U>& x : arr){
        os << "    " << x << endll;
    }
    os << "}";
    return os;
}

template <typename T, typename U>
ostream& operator<< (ostream& os, const multimap<T, U>& arr){
    os << "{\n";
    for(const pair<T,U>& x : arr){
        os << "    " << x << endll;
    }
    os << "}";
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

// File 1: /t/Debugging/setdbg.cpp

template <typename T>
ostream& operator<< (ostream& os, const set<T>& arr){
	os << "[";
    for(const T x : arr){
		os << x << " ";
	}
	os << "]";
    return os;
}

template <typename T>
ostream& operator<< (ostream& os, const multiset<T>& arr){
    os << "[";
    for(const T x : arr){
        os << x << " ";
    }
    os << "]";
    return os;
}

template <typename T>
ostream& operator<< (ostream& os, const unordered_set<T>& arr){
    os << "[";
    for(const T x : arr){
        os << x << " ";
    }
    os << "]";
    return os;
}
inline void open(string name){
    freopen((name + ".in").c_str(), "r", stdin);
	freopen((name + ".out").c_str(), "w", stdout);
}

struct pos{
    int x, y;
    pos operator-(pos b){
        return {this->x - b.x, this->y - b.y};
    }
    pos operator+(pos b){
        return {this->x + b.x, this->y + b.y};
    }
    pos operator*(int b){
        return {this->x * b, this->y * b};
    }
    friend ostream& operator<< (ostream& os, const pos& p){
        return os << "(" << p.x << ", " << p.y << ")";
    }
    bool operator< (const pos& o) const{
        return this->x < o.x || (this->x == o.x && this->y < o.y);
    }
};

vector<pos> generateNodes(vector<pos> antennas){
    vector<pos> nodes;
    for(int i = 0; i < antennas.size(); i++){
        for(int j = 0; j < antennas.size(); j++){
            if(i == j){
                continue;
            }
            pos a = antennas[i];
            pos b = antennas[j];
            pos delta = b - a;
            nodes.push_back(a - delta);
            nodes.push_back(b + delta);
        }        
    }
    return nodes;
}

ll solve(vector<string>& grid)
{
    int n = grid.size();
    int m = grid[0].size();

    map<char, vector<pos>> towers;
    set<pos> nodes;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            switch(grid[i][j]){
                case '.':
                case '#':
                    break;
                default:
                    towers[grid[i][j]].push_back({i, j});
            }
        }
    }
    //dbg(towers);
    
    for(auto& x : towers){
        //dbg(x.first);
        vector<pos> poss = generateNodes(x.second);
        for(int i = poss.size() - 1; i >= 0; i--){
            if(poss[i].x < 0 || poss[i].y < 0 || poss[i].x >= n || poss[i].y >= m){
                poss.erase(poss.begin() + i);
            }
        }
        //dbg(poss);
        nodes.insert(all(poss));
    }
    return nodes.size();
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

    cout << solve(grid) << endll;
    
}
