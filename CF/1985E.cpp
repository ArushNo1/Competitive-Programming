#pragma GCC optimize("Ofast")
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

typedef tree<int,null_type,less<int>,rb_tree_tag,
tree_order_statistics_node_update> indexed_set;


#define endll "\n"

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

#define tr(c,i) for(__typeof__((c)).begin() i = (c).begin(); i != (c).end(); i++)
#define present(c,x) ((c).find(x) != (c).end())

#define cpresent(c,x) (find(all(c),x) != (c).end())

#define sz(a) ll((a).size())
#define MOD ll(1e9+7)
#define INF ll(2e63-1)
#define dbg(x) cout << __LINE__ << ": " << #x << "=" << x << endl;

void fillv(vi& v, int n) {
    for (int i = 0; i < n; ++i) {
        std::cin >> v[i];
    }
}

inline void open(const char * fin, const char * fout)
{
    freopen(fin, "r", stdin);
    freopen(fout, "w", stdout);
}
pair<ll,ll> solve2(ll v){
    ll start = (ll) ceil(sqrt(v));
    ll f, g;
    for(ll i = start; i >= 1; i--){
        if(v % i == 0){
            f = i;
            g = v / i;
            break;
        }
    }
    return make_pair(f, g);
}
ll x, y, z;

ll inline calc(ll f, ll g, ll h){
    return (x + 1 - f) * (y + 1 - g) * (z + 1 - h);
}

void solve()
{
    ll v;
    cin >> x >> y >> z >> v;
    ll k = x * y * z;
    if(v > k){
        cout << 0 << endll;
        return;
    }
    if(v == k){
        cout << 1 << endll;
        return;
    }
    ll start = (ll) ceil(cbrt(v));
    //cerr << "start: " << start << endll;
    ll f, g, h;
    for(ll i = start; i >= 1; i--){
        if(v % i == 0){
            f = i;
            pair<ll, ll> gh = solve2(v / i);
            g = gh.first;
            h = gh.second;
            break;
        }
    }
    //cerr << "f " << f << " g " << g << " h " << h << endll;
    ll maxn = calc(f, g, h);
    maxn = max(maxn, calc(f, h, g));
    maxn = max(maxn, calc(g, f, h));
    maxn = max(maxn, calc(h, f, g));
    maxn = max(maxn, calc(g, h, f));
    maxn = max(maxn, calc(h, g, f));
    if(maxn < 0){
        cout << 0 << endll;
        return;
    }
    cout << maxn << endll;
    //minimize x + y, where x * y = k;
    //floor(sqrt) x, then go down until you find a factor
//minimize x + y + z, where x * y * z = k;
//number of ways to put the box:    (x+1 - x0) * (y + 1 - y0) * (z + 1 - z0);
}



int main()
{
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    ios_base::sync_with_stdio(0);
    
    int T = 1; cin >> T; for(int t = 0; t < T; t++) solve();
}
