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

typedef tree<int, null_type, less<int>, rb_tree_tag,
             tree_order_statistics_node_update>
    indexed_set;

#define endll "\n"

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

#define tr(c, i) for (__typeof__((c)).begin() i = (c).begin(); i != (c).end(); i++)
#define present(c, x) ((c).find(x) != (c).end())

#define cpresent(c, x) (find(all(c), x) != (c).end())

#define sz(a) ll((a).size())
#define MOD ll(1e9 + 7)
#define INF ll(2e63 - 1)
#define dbg(x) cout << __LINE__ << ": " << #x << "=" << x << endl;

inline void fillv(vi &v, int n)
{
    for (int i = 0; i < n; ++i)
    {
        std::cin >> v[i];
    }
}

inline void open(const char *fin, const char *fout)
{
    freopen(fin, "r", stdin);
    freopen(fout, "w", stdout);
}

void solve()
{
}

bool comp(pair<string, int>& a, pair<string, int>& b){
    return a.second < b.second;
}

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    ios_base::sync_with_stdio(0);

    // int T = 1; cin >> T; for(int t = 0; t < T; t++) solve();

    open("notlast.in", "notlast.out");

    int n;
    cin >> n;

    map<string, int> cows { {"Annabelle", 0}, {"Bessie", 0}, {"Daisy", 0}, {"Elsie", 0}, {"Gertie", 0}, {"Henrietta", 0}, {"Maggie", 0}};

    for (int i = 0; i < n; i++)
    {
        string s;
        int x;
        cin >> s >> x;
        cows[s] += x;
    }

    vector<pair<string, int>> cowv(all(cows));
    sort(all(cowv), comp);

    int minm = cowv[0].second;
    for(int i = 1; i < 7; i++){
        auto x = cowv[i];
        cerr << x.second << endll;
        if(x.second > minm){
            
            if(i < 6 && cowv[i + 1].second == x.second){
                cout << "Tie" << endll;
                return 0;
            }
            cout << x.first << endll;
            return 0;
        }
    }
    cout << "Tie" << endll;
}
