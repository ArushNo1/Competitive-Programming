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

void print(vi &arr)
{
    for (auto &x : arr)
    {
    }
}

void print(map<int, int> &arr)
{
    for (auto &x : arr)
    {
    }
}

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    ios_base::sync_with_stdio(0);

    open("milkorder.in", "milkorder.out");

    int n, m, k;
    cin >> n >> m >> k;
    vi milking_positions(n, -1);
    map<int, int> desired_positions;

    vi hier_cows(m);
    fillv(hier_cows, m);

    for (int i = 0; i < k; i++)
    {
        int cow, desired_pos;
        cin >> cow >> desired_pos;
        desired_pos--;
        desired_positions[cow] = desired_pos;
        milking_positions[desired_pos] = cow;
    }

    bool run_reverse_iter = false;

    int pos_index = n - 1;
    int current_cow_index = m - 1;
    for (; current_cow_index >= 0 && pos_index >= 0; current_cow_index--)
    {
        int cur_cow = hier_cows[current_cow_index];
        if (cur_cow == 1)
        {
            run_reverse_iter = true;
            current_cow_index++;
            break;
        }

        if (desired_positions.count(cur_cow) != 0)
        {
            pos_index = desired_positions[cur_cow] - 1;
            continue;
        }
        while (milking_positions[pos_index] != -1)
            pos_index--;
        milking_positions[pos_index] = cur_cow;
        pos_index--;
    }
    

    if (run_reverse_iter)
    {
        int max_cow_index = current_cow_index;
        pos_index = 0;
        while (milking_positions[pos_index] != -1)
            pos_index++;
        for (int j = 0; j < max_cow_index && pos_index < n; j++)
        {
            int cur_cow = hier_cows[j];
            if (cur_cow == 1)
            {
                while (milking_positions[pos_index] != -1)
                    pos_index++;
                cout << (pos_index + 1) << endll;
                return 0;
            }

            if (desired_positions.count(cur_cow) != 0)
            {
                pos_index = desired_positions[cur_cow] + 1;
                continue;
            }
            while (milking_positions[pos_index] != -1)
                pos_index++;
            milking_positions[pos_index] = cur_cow;
            pos_index++;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (milking_positions[i] == -1 || milking_positions[i] == 1)
        {
            cout << (i + 1) << endll;
            return 0;
        }
    }
}
