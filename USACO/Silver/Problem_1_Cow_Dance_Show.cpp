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

int main()
{
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    ios_base::sync_with_stdio(0);
    
	
	open("cowdance");
    //int T = 1; cin >> T; for(int t = 0; t < T; t++) solve();
    int n, t_max;
    cin >> n >> t_max;
    
    vi cows(n);
    fillv(cows, n);

    auto eval = [&](int k){
        multiset<int> dancers;
        for(int i = 0; i < k; i++){
            dancers.insert(cows[i]);
        }
        int t = 0;
        for(int i = k; i < n; i++){
            auto beg = dancers.begin();
            t = *beg;
            if(t > t_max) return false;
            dancers.erase(beg);
            dancers.insert(cows[i] + t);
        }
        return *dancers.rbegin() <= t_max;
    };

    int low = 1, high = n;
    while(low < high){
        int mid = low + (high - low) / 2;
        if(eval(mid)){
            high = mid;
        }
        else{
            low = mid + 1;
        }
    }

    cout << low << endll;
}
