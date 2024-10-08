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


inline void open(const char * fin, const char * fout)
{
    freopen(fin, "r", stdin);
    freopen(fout, "w", stdout);
}

void solve()
{
    cout << "Hello";
}

int main()
{
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    
    //int T = 1; cin >> T; for(int t = 0; t < T; t++) solve();
    int n, m, k;
    cin >> n >> m >> k;
    vi people(n);
    for(int i = 0; i < n; i++){
        cin >> people[i];
    }
    vi apartments(m);
    for(int i = 0; i < m; i++){
        cin >> apartments[i];
    }
    std::sort(people.begin(), people.end());
    std::sort(apartments.begin(), apartments.end());
    int counter = 0;
    int p = 0, a = 0;
    while(p < n && a < m){
        int diff = people[p] - apartments[a];
        if(abs(diff) <= k){
            counter++;
            p++;
            a++;
        }
        else if(diff > 0){
            a++;
        }
        else {
            p++;
        }
    }
    cout << counter;
}
