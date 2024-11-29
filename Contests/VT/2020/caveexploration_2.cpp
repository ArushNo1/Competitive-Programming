#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops") 
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef vector<bool> vb;

#define endll '\n'

#define all(x) (x).begin(), (x).end()
#define MOD ll(1e9+7)
#define inf int(2e31-1)
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

struct node{
    int x, y;
    ll cost;
    node(int x, int y, ll cost): x(x), y(y), cost(cost) {}
    bool operator> (const node& o) const{
        return cost > o.cost;
    }
    bool operator< (const node& o) const{
        return cost < o.cost;
    }
};

pll next_node(priority_queue<node, vector<node>, less<node>>& q, vector<vector<bool>>& vis){
    while(!q.empty() && vis[q.top().x][q.top().y]){
        q.pop();
    }
    if(q.empty()){
        return pll(-1, -1);
    }
    return pll(q.top().x, q.top().y);
}

void solve(int num_tc)
{
    int n; cin >> n;
    vector<vector<ll>> dist(n, vector<ll>(n));
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            cin >> dist[i][j];
        }
    }
    auto eval = [&](ll x){
        //determine if it is possible to go from 0 0 to n - 1, n - 1 with a max height of x
        priority_queue<node, vector<node>, less<node>> q;
        q.push(node(0, 0, 0));
        vector<vector<bool>> vis(n, vector<bool>(n, false));
        while(!q.empty()){
            node cur = q.top();
            q.pop();
            if(cur.x == n - 1 && cur.y == n - 1){
                return true;
            }
            if(vis[cur.x][cur.y]){
                continue;
            }
            vis[cur.x][cur.y] = true;
            for(int i = 0; i < 4; ++i){
                int nx = cur.x + (i == 0 ? 1 : i == 1 ? -1 : 0);
                int ny = cur.y + (i == 2 ? 1 : i == 3 ? -1 : 0);
                if(nx < 0 || nx >= n || ny < 0 || ny >= n){
                    continue;
                }
                if(dist[nx][ny] > x){
                    continue;
                }
                q.push(node(nx, ny, max(cur.cost, dist[nx][ny])));
            }
        }
        return false;
    };
    ll low = dist.back().back(), high = 1e9;
    while(low < high){
        ll mid = (low + high) / 2;
        if(eval(mid)){
            high = mid;
        } else {
            low = mid + 1;
        }
    }
    cout << low << endll;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);  

    ll T = 1;
    //cin >> T;
    for(ll t = 0; t < T; t++){
        solve(t+1);
    }
}
