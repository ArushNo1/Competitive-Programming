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

//comment to enable debugging
#define dbg(x)

#ifndef dbg
#define dbg(x) cerr << __LINE__ << ": " << #x << "=" << x << endl;
//edit for specific DS
#include "cp-templates/Debugging/alldebug.h"
#endif

bool topSort(vector<ll>& sorted, vector<unordered_set<ll>>& adjList, vector<unordered_set<ll>>& radjList)
{
	int N = (adjList).size();
	vector<ll> noEdge{};
	
	for(ll i = 0; i < N; i++)
	{
		if(adjList[i].size() == 0) noEdge.push_back(i);
	}
	
	while(!noEdge.empty())
	{
		ll cur = noEdge.back();
		noEdge.pop_back();
		
		sorted.push_back(cur);
		for(ll n : radjList[cur])
		{
			if(adjList[n].size() == 0) continue;
			
			adjList[n].erase(cur);
			if(adjList[n].size() == 0) noEdge.push_back(n);
		}
	}
	
	bool possible = true;
	for(ll i = 0; i < N; i++)
	{
		possible = possible && adjList[i].empty();
	}
	reverse(all(sorted));
	return possible;
}

void solve(int num_tc)
{
    int n, m;
    cin >> n >> m;

    vector<unordered_set<ll>> adjList(n);
    vector<unordered_set<ll>> radjList(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        adjList[a].insert(b);
        radjList[b].insert(a);
    }

    vector<ll> sorted;

    bool possible = topSort(sorted, adjList, radjList);
    if (possible) {
        for (int i = 0; i < n; i++) {
            cout << sorted[i] + 1 << " ";
        }
        cout << endll;
    } else {
        cout << "IMPOSSIBLE" << endll;
    }
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
