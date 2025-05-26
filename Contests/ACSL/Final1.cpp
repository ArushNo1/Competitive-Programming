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

vvi spiral;

pair<int, int> positionOf(int x){
    for(int i = 0; i < spiral.size(); i++){
        for(int j = 0; j < spiral[i].size(); j++){
            if(spiral[i][j] == x){
                return {i, j};
            }
        }
    }
    return {-1, -1};
}


int solveInward(int horiz, int vert, int M, int N) {
    spiral.resize(vert, vi(horiz, 0));
    int num = 1;
    int top = 0, bottom = vert - 1, left = 0, right = horiz - 1;
    while(top <= bottom && left <= right) {
        for(int i = left; i <= right; i++){
            spiral[top][i] = num++;
        }
        top++;
        for(int i = top; i <= bottom; i++){
            spiral[i][right] = num++;
        }
        right--;
        if(top <= bottom) {
            for(int i = right; i >= left; i--){
                spiral[bottom][i] = num++;
            }
            bottom--;
        }
        if(left <= right) {
            for(int i = bottom; i >= top; i--){
                spiral[i][left] = num++;
            }
            left++;
        }
    }
    pair<int, int> pos1 = positionOf(M);
    pair<int, int> pos2 = positionOf(N);
    return abs(pos1.first - pos2.first) + abs(pos1.second - pos2.second);
}

int solveOutward(int horiz, int vert, int M, int N) {
    int num = 1;
    spiral.resize(vert, vi(horiz, 0));
    for(int i = 0; i < horiz; i++){
        spiral[0][i] = num++;
    }
    for(int i = 1; i < vert; i++){
        spiral[i][horiz - 1] = num++;
    }
    for(int i = horiz - 2; i >= 0; i--){
        spiral[vert - 1][i] = num++;
    }
    //now the cursor is at bottom left corner
    while(num <= max(M, N)) {
        //move up
        for(int i = spiral.size() - 1; i >= 0; i--){
            spiral[i].insert(spiral[i].begin(), num++);
        }
        //move right
        spiral.insert(spiral.begin(), vi(0));
        for(int i = 0; i < spiral[1].size(); i++){
            spiral[0].push_back(num++);
        }
        //move down
        for(int i = 0; i < spiral.size(); i++){
            spiral[i].push_back(num++);
        }
        //move left
        spiral.push_back(vi(spiral[0].size(), 0));
        for(int i = spiral[0].size() - 1; i >= 0; i--){
            spiral[spiral.size() - 1][i] = num++;
        }
    }
    pair<int, int> pos1 = positionOf(M);
    pair<int, int> pos2 = positionOf(N);
    return abs(pos1.first - pos2.first) + abs(pos1.second - pos2.second);
}


int findManDist(string direction, int horiz, int vert, int M, int N) {
    if(direction == "inward"){
        return solveInward(horiz, vert, M, N);
    }
    return solveOutward(horiz, vert, M, N);
}


void solve(int num_tc)
{
    string s;
    cin >> s;
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    cout << findManDist(s, a, b, c, d) << endll;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);  
    dbg("turn off debugging");
    ll T = 1;
    //cin >> T;
    for(ll t = 0; t < T; t++){
        solve(t+1);
    }
}
