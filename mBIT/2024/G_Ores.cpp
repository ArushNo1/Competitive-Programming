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

void fillv(vi &v, int n)
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

int get_comp(int row)
{
    switch(row){
        case 143:
        case 150:
        case 161:
        case 139:
        case 157:
            return 300 - row;
            break;
        default:
            return -1;
    }
    /*
    M+B: 143
    M+I: 150
    M+T: 161
    B+I: 139
    B+T: 150
    I+T: 157
    */
    return 300 - row;
}

void print(map<int, int> & myMap){
    cerr << "\t" ;
    for(const auto& elem : myMap)
    {
        std::cerr << "{" << elem.first << ", " << elem.second << "}, ";
    }
    cerr << endl;
}

void solve()
{
    int n;
    cin >> n;
    vector<string> grid(n);
    for (int i = 0; i < n; i++)
    {
        cin >> grid[i];
    }
    int count = 0;
    for (int c1 = 0; c1 < n; c1++)
    {
        for (int c2 = c1 + 1; c2 < n; c2++)
        {
            cerr << "picking c:s " << c1 << "-" << c2 << endll;
            map<int, int> rows;
            for (int r = 0; r < n; r++)
            {
                int row = grid[r][c1] + grid[r][c2];
                if(row == -1) continue;
                count += rows[row];
                rows[get_comp(row)]++;
                cerr << "after row " << r << endll;
                print(rows);
            }
            
        }
    }
    cout << count << endll;
}

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    ios_base::sync_with_stdio(0);

    int T = 1; cin >> T; for(int t = 0; t < T; t++) solve();
}
