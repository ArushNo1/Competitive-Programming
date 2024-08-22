#pragma region // template
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

#define tr(c,i) for(__typeof__((c)).begin() i = (c).begin(); i != (c).end(); i++)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())

#define MOD ll(1e9+7)
#define INF ll(2e63-1)
#define dbg(x) cerr << __LINE__ << ": " << #x << "=" << x << endll;
#define dbgl(x,l) cerr << #l << " " << l << ": " << #x << "=" << x << endll;

template <typename T>
ostream& operator<< (ostream& os, const vector<T>& arr){
	os << "[";
    for(T x : arr){
		os << x << ", ";
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
ostream& operator<< (ostream& os, const unordered_map<T, U>& arr){
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



template<typename T>
using svec = map<string, T>;

#pragma endregion


struct ing{
	int capacity, durability, flavor, texture, calories;
	ing(int a, int b, int c, int d, int e) : capacity(a), durability(b), flavor(c), texture(d), calories(e){};
	ing operator+(const ing& a){
		return {capacity + a.capacity, durability + a.durability, flavor + a.flavor, texture + a.texture, calories + a.calories};
	}
	ing operator*(const int q){
		return {capacity * q, durability * q, flavor * q, texture * q, calories * q};
	}
};


void printcombs(){
	for(int a = 0; a <= 100; a++){
		for(int b = 0; b <= (100 - a); b++){
			for(int c = 0; c <= (100 - a - b); c++){
				int d = 100 - a - b - c;
				cout << a << " " << b << " " << c << " " << d << endll;
			}
		}
	}
}

ostream& operator<<(ostream& os, ing& o){
	return os << o.capacity << " " << o.durability << " " << o.flavor << " " << o.texture << " " << o.calories; 
}



int main()
{
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    ios_base::sync_with_stdio(0);
	//open("abc");
    //int T = 1; cin >> T; for(int t = 0; t < T; t++) solve();
    
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//freopen("debug.txt", "w", stderr);
	
	vi jars;
	int t;
	while(cin >> t){
		jars.push_back(t);
	}
	sort(all(jars));
	vll ways(151);
	ways[0] = 1;
	for(int j : jars){
		for(int i = 0; i < 151; i++){
			if(i >= j){
				ways[i] += ways[i - j];
			}
		}
	}

	dbg(ways);
	
	cout << ways[25] << endll;

}

