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

template<typename T>
std::pair<T, int> floyd_find_cycle(T start, function<T(T)> f) {
    T tort = start;
    T hare = start;
    while(tort != hare){
        tort = f(tort);
        hare = f(f(hare));
    }
    hare = start;
    while(tort != hare){
        tort = f(tort);
        hare = f(hare);
    }
    T mu = tort;
    hare = f(tort);
    int lambda = 1;
    while(tort != hare){
        hare = f(hare);
        lambda++;
    }
    return {mu, lambda};
}

void process(string& s, vi& color){
    if(s == "stop"){
        exit(0);
    }
    int c = 0;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == ' '){
            c++;
        }
        else{
            color[s[i] - '0'] = c;
        }
    }
}

void solve(int num_tc)
{

    vi color(10);
    //1 stays behind
    cout << "next 0 2 3 4 5 6 7 8 9" << endl;
    string s;
    getline(cin, s);
    cout << "next 0" << endl;
    getline(cin, s);
    process(s, color);
    while(color[0] != color[2]){
        cout << "next 0 2 3 4 5 6 7 8 9" << endl;
        getline(cin, s);
        cout << "next 0" << endl;
        getline(cin, s);
        process(s, color);
    }
    //now 0 2 ... are at the same place, 1 is at the beginning
    while(color[0] != color[1]){
        cout << "next 0 1 2 3 4 5 6 7 8 9" << endl;
        getline(cin, s);
        process(s, color);
    }
    cout << "done" << endl;
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
