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
typedef pair<int, int> ii;
typedef long long ll;
typedef vector<ll> vll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef vector<bool> vb;

#define endll '\n'

#define all(x) (x).begin(), (x).end()

#define MOD ll(1e9+7)
#define inf int(1e9+1)
#define INF ll(1e18+1)
#define EPS ld(1e-9)

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
namespace internal {
    template <class E> struct csr {
        std::vector<int> start;
        std::vector<E> elist;
        explicit csr(int n, const std::vector<std::pair<int, E>>& edges)
            : start(n + 1), elist(edges.size()) {
            for (auto e : edges) {
                start[e.first + 1]++;
            }
            for (int i = 1; i <= n; i++) {
                start[i] += start[i - 1];
            }
            auto counter = start;
            for (auto e : edges) {
                elist[counter[e.first]++] = e.second;
            }
        }
    };
    
    // Reference:
    // R. Tarjan,
    // Depth-First Search and Linear Graph Algorithms
    struct scc_graph {
      public:
        explicit scc_graph(int n) : _n(n) {}
    
        int num_vertices() { return _n; }
    
        void add_edge(int from, int to) { edges.push_back({from, {to}}); }
    
        // @return pair of (# of scc, scc id)
        std::pair<int, std::vector<int>> scc_ids() {
            auto g = csr<edge>(_n, edges);
            int now_ord = 0, group_num = 0;
            std::vector<int> visited, low(_n), ord(_n, -1), ids(_n);
            visited.reserve(_n);
            auto dfs = [&](auto self, int v) -> void {
                low[v] = ord[v] = now_ord++;
                visited.push_back(v);
                for (int i = g.start[v]; i < g.start[v + 1]; i++) {
                    auto to = g.elist[i].to;
                    if (ord[to] == -1) {
                        self(self, to);
                        low[v] = std::min(low[v], low[to]);
                    } else {
                        low[v] = std::min(low[v], ord[to]);
                    }
                }
                if (low[v] == ord[v]) {
                    while (true) {
                        int u = visited.back();
                        visited.pop_back();
                        ord[u] = _n;
                        ids[u] = group_num;
                        if (u == v) break;
                    }
                    group_num++;
                }
            };
            for (int i = 0; i < _n; i++) {
                if (ord[i] == -1) dfs(dfs, i);
            }
            for (auto& x : ids) {
                x = group_num - 1 - x;
            }
            return {group_num, ids};
        }
    
        std::vector<std::vector<int>> scc() {
            auto ids = scc_ids();
            int group_num = ids.first;
            std::vector<int> counts(group_num);
            for (auto x : ids.second) counts[x]++;
            std::vector<std::vector<int>> groups(ids.first);
            for (int i = 0; i < group_num; i++) {
                groups[i].reserve(counts[i]);
            }
            for (int i = 0; i < _n; i++) {
                groups[ids.second[i]].push_back(i);
            }
            return groups;
        }
    
      private:
        int _n;
        struct edge {
            int to;
        };
        std::vector<std::pair<int, edge>> edges;
    };
    
    }  // namespace internal

struct two_sat {
    public:
      two_sat() : _n(0), scc(0) {}
      explicit two_sat(int n) : _n(n), _answer(n), scc(2 * n) {}
  
      void add_clause(int i, bool f, int j, bool g) {
          assert(0 <= i && i < _n);
          assert(0 <= j && j < _n);
          scc.add_edge(2 * i + (f ? 0 : 1), 2 * j + (g ? 1 : 0));
          scc.add_edge(2 * j + (g ? 0 : 1), 2 * i + (f ? 1 : 0));
      }
      bool satisfiable() {
          auto id = scc.scc_ids().second;
          for (int i = 0; i < _n; i++) {
              if (id[2 * i] == id[2 * i + 1]) return false;
              _answer[i] = id[2 * i] < id[2 * i + 1];
          }
          return true;
      }
      std::vector<bool> answer() { return _answer; }
  
    private:
      int _n;
      std::vector<bool> _answer;
      internal::scc_graph scc;
  };

//comment to enable debugging
#define dbg(x)

#ifndef dbg
#define dbg(x) cerr << __LINE__ << ": " << #x << "=" << x << endl;
//edit for specific DS
#include "cp-templates/Debugging/alldebug.h"
#endif

void solve(int num_tc)
{
    int n, m;
    cin >> n >> m;
    two_sat ts(m);
    for(int i = 0; i < n; i++){
        char t;
        cin >> t;
        int p;
        cin >> p;
        char u;
        cin >> u;
        int q;
        cin >> q;
        ts.add_clause(p - 1, t == '+', q - 1, u == '+');
    }
    if(!ts.satisfiable()){
        cout << "IMPOSSIBLE" << endll;
        return;
    }
    auto ans = ts.answer();
    for(int i = 0; i < m; i++){
        if(ans[i]){
            cout << "+";
        }
        else{
            cout << "-";
        }
        cout << " ";
    }
    cout << endll;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);  
    dbg("turn off debugging");
    ll T = 1;
    //cin >> T;
    for(ll t = 0; t < T; t++){
        solve(t+1);
    }
}
