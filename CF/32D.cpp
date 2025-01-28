#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

template <class T>
using indexed_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

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
#define maxeq(a, b) a = max<decltype(a)>(a, b)
#define mineq(a, b) a = min<decltype(a)>(a, b)

#define MOD ll(1e9 + 7)
#define inf int(1e9 + 1)
#define INF ll(1e18 + 1)
#define EPS ld(1e-9)

template <typename T>
inline void fillv(vector<T> &v, int n)
{
    for (int i = 0; i < n; ++i)
    {
        std::cin >> v[i];
    }
}
template <typename T, typename U>
inline void fillv(vector<pair<T, U>> &v, int n, bool inv = false)
{
    if (inv)
    {
        for (int i = 0; i < n; ++i)
        {
            cin >> v[i].second >> v[i].first;
        }
        return;
    }
    for (int i = 0; i < n; ++i)
    {
        cin >> v[i].first >> v[i].second;
    }
    return;
}

inline void open(string name)
{
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
}

// comment to enable debugging
#define dbg(x)

#ifndef dbg
#define dbg(x) cerr << __LINE__ << ": " << #x << "=" << x << endl;
// edit for specific DS
#include <alldebug.h>
#endif

struct star
{
    int x, y;
    int r;
    star(int x, int y, int r) : x(x), y(y), r(r) {};
    bool operator<(const star &s) const
    {
        if (r != s.r)
        {
            return r < s.r;
        }
        if (y != s.y)
        {
            return y < s.y;
        }
        return x < s.x;
    }
    friend ostream &operator<<(ostream &os, const star &s)
    {
        int x0 = s.x + 1;
        int y0 = s.y + 1;
        os << x0 << " " << y0 << endll;
        os << x0 - s.r << " " << y0 << endll;
        os << x0 + s.r << " " << y0 << endll;
        os << x0 << " " << y0 - s.r << endll;
        os << x0 << " " << y0 + s.r << endll;
        return os;
    }
};

void solve(int num_tc)
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<string> grid(n);
    fillv(grid, n);
    for (int dc = 1; dc < m; dc++)
    {
        for (int r = dc; r + dc < n; r++)
        {
            for (int c = dc; c + dc < m; c++)
            {
                if (grid[r][c] == '*')
                {
                    if (grid[r][c + dc] == '*' && c >= dc && grid[r][c - dc] == '*' && r >= dc && grid[r - dc][c] == '*' && r + dc < n && grid[r + dc][c] == '*')
                    {
                        k--;
                        if(k == 0){
                            cout << star(r, c, dc) << endll;
                            return;
                        }
                    }
                }
            }
        }
    }

    cout << -1 << endll;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll T = 1;
    // cin >> T;
    for (ll t = 0; t < T; t++)
    {
        solve(t + 1);
    }
}
