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
    
    open("convention");
    

    int n, m, k;
    cin >> n >> m >> k;

    
    
    if(m == n || n == 1 || k == 1){
        cout << 0 << endll;
        return 0;
    }
    
    vi times(n);
    fillv(times, n);
    sort(all(times));
	
    if(m == 1){
        cout << times[n - 1] - times[0] << endll;
        return 0;
    }
	//int T = 1; cin >> T; for(int t = 0; t < T; t++) solve();
    auto eval = [&](int wt) -> bool{
        //first cow time, num cows in it
        //dbg(wt);
        int num_buses = 1;
        ii current_bus = {times[0], 0};
        for(int i = 0; i < n; i++){
            //dbg(i);
            int c = times[i];
            //dbg(c);
            //dbg(current_bus);
            if((current_bus.second == k) || (c - current_bus.first) > wt) {
                //cerr << "new bus" << endll;
                current_bus.first = c;
                current_bus.second = 1;
                num_buses++;
                //dbg(num_buses);
                if(num_buses > m){
                    //cerr << "too many buses" << endll;
                    return false;
                }
            }
            else{
                current_bus.second++;
                //dbg(current_bus.second);
            }
        }
        //if(current_bus.second == 0) num_buses--;
        //dbg(num_buses);
        return num_buses <= m;
    };

    int low = 0, high = 2e9;
    while(low < high){
        int mid = low + (high - low) / 2;
        //dbg(mid);
        //dbg(eval(mid));
        if(eval(mid)){
            high = mid;
        } else {
            low = mid + 1;
        }
    }
    dbg(low);
    cout << low << endll;
}