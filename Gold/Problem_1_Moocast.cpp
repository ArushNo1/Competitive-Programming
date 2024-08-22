#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops") 
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
typedef pair<ll, ll> pll;
typedef vector<bool> vb;

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
#define dbg(x) cerr << __LINE__ << ": " << #x << "=" << x << endl;

template <typename T>
ostream& operator<< (ostream& os, vector<T>& arr){
	os << "[";
    for(T& x : arr){
		os << x << " ";
	}
	os << "]";
    return os;
}

template <typename T, typename U>
ostream& operator<< (ostream& os, pair<T, U>& x){
    os << "(" << x.first << ", " << x.second << ")";
    return os;
}

template <typename T, typename U>
ostream& operator<< (ostream& os, vector<pair<T, U>>& arr){
	os << "{\n";
    for(const pair<T,U>& x : arr){
		os << "    (" << x.first << ", " << x.second << ")\n";
	}
	os << "}";
    return os;
}

template <typename T>
void print(vector<vector<T>>& mat, ostream& os = cerr){
	for(vector<T>& arr : mat){
		for(T& x : arr){
			os << x << " ";
		}
		os << endll;
	}
}

template <typename T>
void print(vector<T>& arr, ostream& os = cerr){
	for(T& x : arr){
			os << x << " ";
	}
	os << endll;
}

template <typename T>
void print(T obj, ostream&os = cerr){
	os << obj << endll;
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

inline void open(const char * fin, const char * fout)
{
    freopen(fin, "r", stdin);
    freopen(fout, "w", stdout);
}

void solve()
{

}

inline ll dist2(pll& a, pll& b){
    return pow(a.first - b.first, 2) + pow(a.second - b.second,2);
}

ostream& operator<<(ostream& os, queue<int> q){
    os << "{\n   ";
    while(!q.empty()){
        os << "" << q.front() << " ";
        q.pop();
    }
    return os << "\n}";
}

int main()
{
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    ios_base::sync_with_stdio(0);
	open("moocast");
    //int T = 1; cin >> T; for(int t = 0; t < T; t++) solve();
    
	ll n;
    cin >> n;

    vector<vector<pair<int,ll>>> adj(n);
    vector<pll> cows(n);
    for(int i = 0; i < n; i++){
        cin >> cows[i].first >> cows[i].second;
        for(int j = 0; j < i; j++){
            ll d = dist2(cows[i], cows[j]);
            adj[i].push_back({j, d});
            adj[j].push_back({i, d});
        }
    }

    //print(adj);

    auto eval = [&](ll X){
        int num_visited = 0;
        vb visited(n);
        queue<int> bfs;
        bfs.push(0);
        visited[0] = true;
        while(!bfs.empty()){
            int node = bfs.front();
            //dbg(bfs);
            //dbg(node);
            bfs.pop();
            num_visited++;
            for(pair<int,ll> nb : adj[node]){
                if(!visited[nb.first] && nb.second <= X){
                    bfs.push(nb.first);
                    visited[nb.first] = true;
                }
            }
        }
        return num_visited == n;
    };

    

    ll low = 0, high = 2e9 + 5;
    while(low < high){
        ll mid = (low + high) / 2;
        //dbg(mid);
        if(eval(mid)){
            high = mid;
        }
        else{
            low = mid + 1;
        }
    }

    cout << low << endll;
}
