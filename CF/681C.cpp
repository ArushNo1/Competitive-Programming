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

vector<string> ops = {"insert", "getMin", "removeMin"};

void solve(int num_tc)
{
    int n;
    cin >> n;
    vector<pll> in(n);
    for(int i = 0; i < n; i++){
        string s; cin >> s;
        if(s == "insert"){
            int t; cin >> t;
            in[i] = {0, t};
        } else if(s == "getMin"){
            int t; cin >> t;
            in[i] = {1, t};
        } else if(s == "removeMin"){
            in[i] = {2, 0};
        }
    }
    dbg(in);
    vector<pll> out;
    multiset<int> ms;
    for(int i = 0; i < n; i++){
        dbg(ms);
        dbg("--");
        dbg(i);
        dbg(ops[in[i].first]);
        dbg(in[i].second);
        if(in[i].first == 0){
            //need to insert element
            ms.insert(in[i].second); //insert
            out.push_back(in[i]); //insert
            continue;
        }
        if(in[i].first == 1){ //getMin
            if(ms.empty()){ //insert then getMin
                ms.insert(in[i].second);
                out.push_back({0, in[i].second});
                out.push_back(in[i]);
            }
            else{ //there's already stuff in there
                while(!ms.empty() && *ms.begin() < in[i].second){
                    out.push_back({2, 0}); //removeMin
                    ms.erase(ms.begin()); //remove Min
                }
                if(ms.empty()){ //same as above
                    ms.insert(in[i].second);
                    out.push_back({0, in[i].second});
                    out.push_back(in[i]);
                }
                else if(*ms.begin() == in[i].second){ //getMin
                    out.push_back(in[i]);
                } else { //insert then getMin
                    ms.insert(in[i].second);
                    out.push_back({0, in[i].second});
                    out.push_back(in[i]);
                }
            }
            continue;
        }
        if(ms.empty()){
            out.push_back({0, 1});
            out.push_back({2, 0});
        } else {
            out.push_back({2, 0});
            ms.erase(ms.begin());
        }
    }
    cout << out.size() << endll;
    for(auto& p : out){
        if(p.first == 2){
            cout << ops[p.first] << endll;
        } else {
            cout << ops[p.first] << " " << p.second << endll;
        }
    }
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
