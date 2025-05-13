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

void solve(int num_tc)
{
    int n, m;
    cin >> n >> m;

    string s;
    cin >> s;
    int S = s.size();
    vector<ll> dx(S + 1);
    vector<ll> dy(S + 1);
    dx[0] = 0;
    dy[0] = 0;
    for(int i = 0; i < S; i++){
        dx[i + 1] = dx[i];
        dy[i + 1] = dy[i];
        if(s[i] == 'U'){
            dx[i + 1]--;
        }
        else if(s[i] == 'D'){
            dx[i + 1]++;
        }
        else if(s[i] == 'L'){
            dy[i + 1]--;
        }
        else if(s[i] == 'R'){
            dy[i + 1]++;
        }
    }
 
    for(int i = 1; i < S + 1; i++){
        dx.push_back((dx[i]) + dx[S]);
        dy.push_back((dy[i]) + dy[S]);
    }

    vector<pair<ll, ll>> xy(n * m);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            ll x;
            cin >> x;
            x--;
            xy[x].first = i;
            xy[x].second = j;
        }
    }
    auto moddist = [&](ll x1, ll x2, ll y1, ll y2){
        return min(abs(x2-x1), n-abs(x2-x1)) + 
               min(abs(y2-y1), m-abs(y2-y1));
    };

    auto newpos = [&](ll x, ll y, ll days, ll sind){
        sind = sind % S;
        ll cyc = days / S;
        ll rem = days % S;
        ll x0 = x + cyc * dx[S] + dx[rem + sind] - dx[sind];
        ll y0 = y + cyc * dy[S] + dy[rem + sind] - dy[sind];
        x0 = (x0 % n + n) % n;
        y0 = (y0 % m + m) % m;
        return make_pair(x0, y0);
    };

    auto mintime = [&](ll sx, ll sy, ll fx, ll fy, ll t){
        ll low = 0, high = n * m;
        while(low < high){
            ll mid = (low + high) / 2;
            //cerr << "can travel " << mid << " days" << endl;
            auto [x1, y1] = newpos(sx, sy, mid, t);
            //cerr << "newpos: " << x1 << " " << y1 << endl;
            ll dist = moddist(x1, fx, y1, fy);
            if(dist <= mid){
                high = mid;
            }
            else{
                low = mid + 1;
            }
        }
        return low;
    };

    ll time = 0;
    ll x = 0;
    ll y = 0;
    for(int i = 0; i < n * m; i++){
        ll x0 = xy[i].first;
        ll y0 = xy[i].second;
        if(x == x0 && y == y0){
            continue;
        }
        dbg(x); dbg(y);
        dbg(x0); dbg(y0);


        ll low = mintime(x, y, x0, y0, time);
        dbg(low);
        
        tie(x, y) = newpos(x, y, low, time);
        time += low;
        x = x0;
        y = y0;
        //break;
    }
    cout << time << endll;
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
