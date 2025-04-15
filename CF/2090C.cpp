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
typedef long long ll;
typedef vector<ll> vll;
typedef pair<ll, ll> pll;

#define endll '\n'

#define all(x) (x).begin(), (x).end()

#define MOD ll(1e9+7)
#define inf int(1e9+1)
#define INF ll(1e18+1)

template <typename T>
inline void fillv(vector<T>& v, int n) {
    for (int i = 0; i < n; ++i) {
        std::cin >> v[i];
    }
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
#include "cp-templates/Debugging/alldebug.h"
#endif

struct cell{
    int x, y;
    int dist;
    cell(int x, int y, int add) : x(x), y(y), dist(x + y + add) {}
    bool operator<(const cell& other) const {
        if(dist != other.dist) return dist < other.dist;
        if(x != other.x) return x < other.x;
        return y < other.y;
    }
    friend ostream& operator<<(ostream& os, const cell& c) {
        return os << "(" << c.x << ", " << c.y << ")";// << ", " << c.dist << ")";
    }
    bool operator==(const cell& other) const {
        return x == other.x && y == other.y;
    }
    bool operator!=(const cell& other) const {
        return !(*this == other);
    }
};

void remove_table(set<cell>& tableopen, cell& t){
    int lr = t.x % 3;
    int x = t.x / 3 * 3;
    int ud = t.y % 3;
    int y = t.y / 3 * 3;
    tableopen.erase(cell(x + lr, y + ud, 0));
    tableopen.erase(cell(x + 3 - lr, y + ud, 0));
    tableopen.erase(cell(x + lr, y + 3 - ud, 0));
    tableopen.erase(cell(x + 3 - lr, y + 3 - ud, 2));
}

void solve(int num_tc)
{
    int n;
    cin >> n;
    set<cell> regopen;
    set<cell> tableopen;
    int placed = 0;
    for(int i = 0; placed < n; i++){
        for(int j = 0; j <= i; j++){
            //i is x + y, j is x
            int x = j;
            int y = i - j; 
            for(auto& t : {cell(3 * x + 1, 3 * y + 1, 0),
                cell(3 * x + 1, 3 * y + 2, 0),
                cell(3 * x + 2, 3 * y + 1, 0),
                cell(3 * x + 2, 3 * y + 2, 2)}){
                tableopen.insert(t);
                regopen.insert(t);
            }
            placed++;
            if(placed == n) break;
        }
    }
    dbg(tableopen);
    dbg(regopen);
    for(int i = 0; i < n; i++){
        int c;
        cin >> c;
        dbg(c);
        if(c == 1){
            auto it = regopen.begin();
            dbg(*it);
            cell t = *it;
            regopen.erase(it);
            remove_table(tableopen, t);
            cout << t.x << " " << t.y << endll;
        }
        else{
            auto it = tableopen.begin();
            dbg(*it);
            cell t = *it;
            regopen.erase(t);
            remove_table(tableopen, t);
            cout << t.x << " " << t.y << endll;
        }
        dbg(regopen);
        dbg(tableopen);
    }
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);  
    dbg("turn off debugging");
    ll T = 1;
    cin >> T;
    for(ll t = 0; t < T; t++){
        solve(t+1);
    }
}
