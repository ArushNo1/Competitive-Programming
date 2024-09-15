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


#define endll '\n'

#define all(x) (x).begin(), (x).end()
#define MOD ll(1e9+7)
#define INF ll(2e63-1)
#define EPS ld(1e-9)
#define dbg(x) cerr << __LINE__ << ": " << #x << "=" << x << endll;
#define print(x) cout << __LINE__ << ": " << #x << "=" << x << endll;
#define ans(x) cout << x << endll; return;

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

ostream& operator<< (ostream& os, const vector<jit>& arr){
	os << "{\n";
    for(const jit& x : arr){
		os << "    " << x << endll;
	}
	return os << "}";
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

struct jit{
    int first, second, third;
    jit(int a, int b) : first(a), second(b){
        third = 0;
    };
};

ostream& operator<<(ostream& os, const jit& j){
    return cout << "(" << j.first << ", " << j.second << ", " << j.third << ")";
}

void solve(int num_tc)
{
    int n, m;
    cin >> n >> m;
    //0 - n, 1 - a, ...
    //scores[i][j] = net score of string i starting from letter j;
    vvi scores(n, vi(5));

    string lets = "narek";

    for(int I = 0; I < n; I++){
        string s;
        cin >> s;
        int cscore = 0;
        vector<jit> pts = {{0, 0},{1, 0},{2, 0},{3, 0},{4, 0}};
        for(int i = 0; i < m; i++){
            for(int j = 0; j < 5; j++){
                if(lets[j] == s[i]){
                    ++cscore;
                }
                if(s[i] == lets[pts[j].first]){
                    pts[j].first++;
                    pts[j].second++;
                    if(pts[j].first == 5){
                        pts[j].first = 0;
                        pts[j].third++;
                    }
                }
            }
        }
        dbg(pts);
        for(int i = 0; i < 5; i++){
            scores[I][i] = 2 * (pts[i].third) - cscore;
        }
    }
    dbg(scores);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);  

    ll T = 1;
    cin >> T;
    for(ll t = 0; t < T; t++){
        solve(t+1);
    }
}
