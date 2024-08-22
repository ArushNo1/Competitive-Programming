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

void solve()
{

}

int main()
{
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    ios_base::sync_with_stdio(0);
    
    //int T = 1; cin >> T; for(int t = 0; t < T; t++) solve();
    int n, days;
    cin >> n >> days;
    vector<tuple<int, int, int>> passes(n);
    //expiry, tickets, cost
    for(int i = 0; i < n; i++){
        int t, e, c;
        cin >> t >> e >> c;
        passes[i] = std::make_tuple(e, t, c);
    }
    std::sort(passes.begin(), passes.end());
    if(get<1>(passes[0]) != days){
        cout << -1 << endll;
        return 0;
    }
    for(int day = 0; day < days; day++){
        int diff = abs(get<1>(passes[day]) - get<1>(passes[day + 1]));
        
    }
}
