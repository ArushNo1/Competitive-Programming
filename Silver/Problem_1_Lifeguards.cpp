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

struct shift{
    int time;
    bool start;
    int cow;
    shift(int a, bool b) : time(a), start(b) {};
    shift(int a, bool b, int c) : time(a), start(b), cow(c) {};
    bool operator<(const shift& o) const{
        return this->time < o.time;
    }
    int operator-(const shift& o) const{
        return this->time - o.time;
    }
};

ostream& operator<<(ostream& os, shift& s){
    return os << "c:" << s.cow <<  ", t:" << s.time << ", s:" << s.start;
}

void print(vector<shift>&arr, ostream& os = cerr){
    for(shift& x : arr){
		os << x << endll;
	}
	os << endll;
}

void print(set<int>& arr, ostream& os = cerr){
    os << "cows: " << endll;
    for(const int& x : arr){
        os << x << ", ";
    }
    os << endll;
}

int main()
{
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    ios_base::sync_with_stdio(0);
    
	
	//open("lifeguards");
    //int T = 1; cin >> T; for(int t = 0; t < T; t++) solve();
    int n;
    cin >> n;
    vector<shift> times;
    for(int i = 0; i < n; i++){
        int start, end;
        cin >> start >> end;
        times.push_back({start, true, i});
        times.push_back({end, false, i});
    }

    sort(all(times));
    //print(times);
    
    vi contributions(n);
    int total_time = 0;
    set<int> workers;
    
    for(int i = 0; i < 2 * n; i++){
        shift s = times[i];
        //dbg(s);
        if(s.start) {
            workers.insert(s.cow);
        } else {
            workers.erase(s.cow);
        }
        //print(workers);
        //dbg(workers.size());
        if(workers.size() == 1){
            int cow = *workers.begin();
            //dbg(cow);
            contributions[cow] += times[i + 1] - s;
            //print(contributions);
        }
        if(workers.size() > 0){
            total_time += times[i + 1] - s;
        }
        //dbg(total_time);
    }
    //print(contributions);
    
    int m = *min_element(all(contributions));
    cout << total_time - m << endll;
    
}
