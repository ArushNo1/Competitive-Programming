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

int n, m;

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

bool inbounds(pos p){
    return p.x >= 0 && p.x < n && p.y >= 0 && p.y < m;
}

vector<pos> generateNodes(vector<pos> antennas){
    vector<pos> nodes;
    for(int i = 0; i < antennas.size(); i++){
        for(int j = i + 1; j < antennas.size(); j++){
            if(i == j){
                continue;
            }
            pos a = antennas[j];
            pos b = antennas[i];
            nodes.push_back(a);
            nodes.push_back(b);
            pos delta = b - a;
            for(int k = 1; inbounds(a + (delta * k)); k++){
                nodes.push_back(a + (delta * k));
            }
            for(int k = -1; inbounds(a + (delta * k)); k--){
                nodes.push_back(a + (delta * k));
            }
        }        
    }
    return nodes;
}



struct file{
    int start;
    int end;
    int id;
    int sum(){
        //sum from [start, end)

        return id * ((end * (end - 1) ) - ((start - 1) * (start))) / 2;
    }
    friend ostream& operator<< (ostream& os, const file& f){
        return os << "[" << f.start << ", " << f.end << ", " << f.id << "]";
    }
};

void solve(string s)
{
    vll disk;
    int fileid = 0;
    for(int i = 0; i < s.size(); i++){
        if(i % 2 == 0){
            for(int j = 0; j < s[i] - '0'; j++){
                disk.push_back(fileid);
            }
            fileid++;
        }
        else{
            for(int j = 0; j < s[i] - '0'; j++){
                disk.push_back(-1);
            }
        }
    }
    
    for(int i = 0; i < disk.size(); i++){
        if(disk[i] == -1){
            int id;
            do{
                id = disk.back();
                disk.pop_back();
            } while(id == -1);
            disk[i] = id;
        }
    }

    ll total = 0;
    for(int i = 0; i < disk.size(); i++){
        total += disk[i] * i;
    } 
    cout << total << endll;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);  
    
    string s;
    cin >> s;
    solve(s);    
}
