#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

typedef tree<int, null_type, less<int>, rb_tree_tag,
             tree_order_statistics_node_update>
    indexed_set;

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

#define MOD ll(998244353)
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

ll invMod(ll x, ll mod) {
    if (x <= 1) {
        return x;
    }
    return mod - mod / x * invMod(mod % x, mod) % mod;
}

template <typename T>
T binom(T n, T k, std::vector<T> &fact, std::vector<T> &invfact, T mod, T size = 3e5) {
    if (fact.size() < size + 1) {
        fact.resize(size + 1);
        invfact.resize(size + 1);
        fact[0] = 1;
        for (int i = 1; i <= size; i++) {
            fact[i] = (fact[i - 1] * i) % mod;
        }
        invfact[size] = invMod(fact[size], mod);
        for (int i = size - 1; i >= 0; i--) {
            invfact[i] = (invfact[i + 1] * (i + 1)) % mod;
        }
    }

    return ((fact[n] * invfact[k]) % mod * invfact[n - k]) % mod;
}

// comment to enable debugging
//! #define dbg(x)

#ifndef dbg
#define dbg(x) cerr << __LINE__ << ": " << #x << "=" << x << endl;
// edit for specific DS
#include <alldebug.h>
#endif

vll fact;
vll invfact;

ll result(vi& arr, vi& status){
    ll combs = 0;

    int liars = 0;
    int twos = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (status[i] == 1)
        {
            liars++;
            continue;
        }
        if (status[i] == 2)
        {
            twos++;
            continue;
        }
        if (liars < arr[i])
        {
            int twosneeded = arr[i] - liars;
            if (twos < twosneeded)
            {
                return 0;
            }
            combs += binom<ll>(twos, twosneeded, fact, invfact, MOD);
            liars += twosneeded;
            twos -= twosneeded;
        }
    }
    combs += (liars == 0);
    return combs;
}

void solve(int num_tc)
{
    int n;
    cin >> n;
    vi arr(n);
    fillv(arr, n);

    if (n == 1)
    {
        cout << ((arr[0] == 0) ? 2 : 1) << endll;
        return;
    }
    if (accumulate(all(arr), 0) == 0)
    {
        cout << 2 << endll;
        return;
    }

    vi status(n, 2);
    // 0 for true, 1 for liar, 2 for either

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > (i / 2 + i % 2))
        {
            status[i] = 1;
            if (i > 0 && status[i - 1] == 1)
            {
                cout << 0 << endll;
                return;
            }
            else if (i > 0)
            {
                status[i - 1] = 0;
            }
        }
    }

    bool hasatwo = false;
    for (int i = 0; i < n; i++)
    {
        if (status[i] == 2)
        {
            hasatwo = true;
            break;
        }
    }
    if (!hasatwo)
    {
        cout << 1 << endll;
        return;
    }

    
    if(accumulate(all(status), 0) == 2 * n){
        dbg("all2");
        ll combs = 0;
        status[0] = 1;
        combs += result(arr, status);
        dbg(combs);
        status[0] = 0;
        combs += result(arr, status);
        cout << combs << endll;
        return;
    }
    ll combs = result(arr, status);

    cout << combs << endll;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    binom<ll>(0, 0, fact, invfact, MOD);

    ll T = 1;
    cin >> T;
    for (ll t = 0; t < T; t++)
    {
        solve(t + 1);
    }
}
