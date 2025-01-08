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
#define inf int(1e9+1)
#define INF ll(1e18+1)
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
// File 1: /t/Debugging/setdbg.cpp

template <typename T>
ostream& operator<< (ostream& os, const set<T>& arr){
	os << "[";
    for(const T x : arr){
		os << x << " ";
	}
	os << "]";
    return os;
}

template <typename T>
ostream& operator<< (ostream& os, const multiset<T>& arr){
    os << "[";
    for(const T x : arr){
        os << x << " ";
    }
    os << "]";
    return os;
}

template <typename T>
ostream& operator<< (ostream& os, const unordered_set<T>& arr){
    os << "[";
    for(const T x : arr){
        os << x << " ";
    }
    os << "]";
    return os;
}
void solve(int num_tc)
{
    ll n;
    cin >> n;
    vll arr(n);
    vll pref(n + 1);
    for(ll i = 0; i < n ;i++){
        cin >> arr[i];
        pref[i + 1] = pref[i] + arr[i];
    }        

    map<ll, ll> prefvals;
    vector<pair<ll, ll>> segments;
    for(ll i = 0; i <= n; i++){
        if(prefvals.count(pref[i]) == 0){
            prefvals[pref[i]] = i;
            continue;
        }
        segments.push_back({prefvals[pref[i]], i - 1});
        prefvals[pref[i]] = i;
    }
    if(segments.size() == 0){
        cout << 0 << endll;
        return;
    }
    set<ll> points;
    for(ll i = 0; i < segments.size(); i++){
        if(points.upper_bound(segments[i].first) != points.end()){
            continue;
        }
        else{
            points.insert(segments[i].second);
        }
    }
    cout << points.size() << endll;
    
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
