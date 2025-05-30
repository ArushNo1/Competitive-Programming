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
    int n;
    cin >> n;
    if (n == 1) {
        ll tx, ty;
        cin >> tx >> ty; 
        cout << 1 << endll;
        return;
    }
    if (n == 2){
        ll x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << 2 << endll;
        return;
    }

    vll xo(n), yo(n);
    for (int i = 0; i < n; i++) {
        cin >> xo[i] >> yo[i];
    }

    vll x = xo, y = yo;
    sort(all(x));
    sort(all(y));

    ll xmin = x[0],   xmin2 = x[1];
    ll xmax = x[n-1], xmax2 = x[n-2];
    ll ymin = y[0],   ymin2 = y[1];
    ll ymax = y[n-1], ymax2 = y[n-2];

    ll xmincnt = 0, xmaxcnt = 0, ymincnt = 0, ymaxcnt = 0;
    for (int i = 0; i < n; i++) {
        if (xo[i] == xmin) xmincnt++;
        if (xo[i] == xmax) xmaxcnt++;
        if (yo[i] == ymin) ymincnt++;
        if (yo[i] == ymax) ymaxcnt++;
    }

    ll ans = (xmax - xmin + 1) * (ymax - ymin + 1);
    for (int i = 0; i < n; i++) {
        ll nxmin = xmin, nxmax = xmax;
        ll nymin = ymin, nymax = ymax;

        if (xo[i] == xmin && xmincnt == 1) {
            nxmin = xmin2;
        }
        if (xo[i] == xmax && xmaxcnt == 1) {
            nxmax = xmax2;
        }
        if (yo[i] == ymin && ymincnt == 1) {
            nymin = ymin2;
        }
        if (yo[i] == ymax && ymaxcnt == 1) {
            nymax = ymax2;
        }

        ll width  = nxmax - nxmin + 1;
        ll height = nymax - nymin + 1;
        ll area = width * height;
        if (area >= n) {
            ans = min(ans, area);
            continue;
        }
        area = min(width * (height + 1), height * (width + 1));
        ans = min(ans, area);
    }
    ans = max<ll>(ans, n);
    cout << ans << endll;
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
