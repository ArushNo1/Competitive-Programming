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
typedef long long ll;
typedef vector<ll> vll;
typedef pair<ll, ll> pll;

#define endll '\n'

#define all(x) (x).begin(), (x).end()

#define MOD ll(1e9 + 7)
#define inf int(1e9 + 1)
#define INF ll(1e18 + 1)

template <typename T> inline void fillv(vector<T> &v, int n) {
    for (int i = 0; i < n; ++i) {
        std::cin >> v[i];
    }
}

inline void open(string name) {
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
}

// comment to enable debugging
#define dbg(x)

#ifndef dbg
#define dbg(x) cerr << __LINE__ << ": " << #x << "=" << x << endl;
// edit for specific DS
#include "cp-templates/Debugging/alldebug.h"
#endif

class FiveSAT {
    private:
        int n_vars;
        vector<vector<int>> clauses;
    
    public:
        FiveSAT(int vars) : n_vars(vars) {}
    
        void add_clause(const vector<int>& clause) {
            clauses.push_back(clause); 
        }
    
        int solve() {
            int min_true = INT_MAX;
            int total = 1 << n_vars;
    
            for (int mask = 0; mask < total; ++mask) {
                bool ok = true;
                for (const auto& clause : clauses) {
                    bool clause_satisfied = false;
                    for (int var : clause) {
                        if (mask & (1 << (var - 1))) {
                            clause_satisfied = true;
                            break;
                        }
                    }
                    if (!clause_satisfied) {
                        ok = false;
                        break;
                    }
                }
                if (ok) {
                    int count = __builtin_popcount(mask);
                    min_true = min(min_true, count);
                }
            }
            return (min_true == INT_MAX ? -1 : min_true);
        }
    };

vi dx = {1, 1, -1, -1, 0};
vi dy = {1, -1, 1, -1, 0};

void solve(int num_tc) {
    vector<string> grid(7);
    fillv(grid, 7);

    set<int> variables;
    vector<vector<int>> clauses;

    auto idx = [&](int i, int j) { return i * 7 + j; };

    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 7; j++) {
            if (grid[i][j] == 'W') {
                continue;
            }
            bool fail = false;
            for (int dir = 0; dir < 5; dir++) {
                int ni = i + dx[dir];
                int nj = j + dy[dir];
                if (ni < 0 || ni >= 7 || nj < 0 || nj >= 7) {
                    fail = true;
                    break;
                }
                if (grid[ni][nj] == 'W') {
                    fail = true;
                    break;
                }
            }
            if (!fail) {
                
            }
        }
    }
    FiveSAT sat(variables.size());

}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    dbg("turn off debugging");
    ll T = 1;
    // cin >> T;
    for (ll t = 0; t < T; t++) {
        solve(t + 1);
    }
}
