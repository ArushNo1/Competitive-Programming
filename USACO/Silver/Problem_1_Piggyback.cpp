#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops") 
#include <bits/stdc++.h>
using namespace std;

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
#define inf int(1e9)
#define INF ll(2e63-1)
#define EPS ld(1e-9)
#define dbg(x) cerr << __LINE__ << ": " << #x << "=" << x << endl;

template <typename T>
ostream& operator<< (ostream& os, const vector<T>& arr){
	os << "[";
    for(const T x : arr){
		os << x << " ";
	}
	os << "]";
    return os;
}

template <typename T, typename U>
ostream& operator<< (ostream& os, const pair<T, U>& x){
    os << "(" << x.first << ", " << x.second << ")";
    return os;
}

template <typename T, typename U>
ostream& operator<< (ostream& os, const vector<pair<T, U>>& arr){
	os << "{\n";
    for(const pair<T,U>& x : arr){
		os << "    " << x << endll;
	}
	os << "}";
    return os;
}

template <typename T, typename U>
ostream& operator<< (ostream& os, const map<T, U>& arr){
	os << "{\n";
    for(const pair<T,U>& x : arr){
		os << "    " << x << endll;
	}
	os << "}";
    return os;
}

template <typename T>
inline void fillv(vector<T>& v, int n) {
    for (int i = 0; i < n; ++i) {
        std::cin >> v[i];
    }
}
template <typename T, typename U>
inline void fillv(vector<pair<T, U>>& v, int n, bool inv = false){
	if(inv){
		for(int i = 0 ; i < n; ++i){
			cin >> v[i].second >> v[i].first;
		}
		return;
	}
	for (int i = 0; i < n; ++i) {
        cin >> v[i].first >> v[i].second;
    }
	return;
}

inline void open(string name){
    freopen((name + ".in").c_str(), "r", stdin);
	freopen((name + ".out").c_str(), "w", stdout);
}

void solve(int num_tc)
{
    int benergy, eenergy, penergy;
    int n, m;
    cin >> benergy >> eenergy >> penergy >> n >> m;

    vvi adj(n + 1);
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vi distb(n + 1, inf);
    distb[1] = 0;
    vi diste(n + 1, inf);
    diste[2] = 0;
    vi distn(n + 1, inf);
    distn[n] = 0;

    queue<int> bfs;
    bfs.push(1);
    while(!bfs.empty()){
        int u = bfs.front();
        bfs.pop();
        for(int nb : adj[u]){
            if(distb[nb] == inf){
                distb[nb] = distb[u] + 1;
                bfs.push(nb);
            }
        }
    }

    bfs.push(2);
    while(!bfs.empty()){
        int u = bfs.front();
        bfs.pop();
        for(int nb : adj[u]){
            if(diste[nb] == inf){
                diste[nb] = diste[u] + 1;
                bfs.push(nb);
            }
        }
    }

    bfs.push(n);
    while(!bfs.empty()){
        int u = bfs.front();
        bfs.pop();
        for(int nb : adj[u]){
            if(distn[nb] == inf){
                distn[nb] = distn[u] + 1;
                bfs.push(nb);
            }
        }
    }

    int dist = inf;
    for(int i = 1; i <= n; i++){
        dist = min(dist, distb[i] * benergy + diste[i] * eenergy + distn[i] * penergy);
    }


    cout << dist << endll;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);  
    open("piggyback");
    ll T = 1;
    //cin >> T;
    for(ll t = 0; t < T; t++){
        solve(t+1);
    }
}
