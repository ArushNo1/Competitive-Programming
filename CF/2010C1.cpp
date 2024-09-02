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

class HashedString {

  private:

    // change M and B if you want

    static const long long M = 1e9 + 9;

    static const long long B = 9973;


    // pow[i] contains B^i % M

    static vector<long long> pow;


    // p_hash[i] is the hash of the first i characters of the given string

    vector<long long> p_hash;


  public:

    HashedString(const string &s) : p_hash(s.size() + 1) {

        while (pow.size() <= s.size()) { pow.push_back((pow.back() * B) % M); }


        p_hash[0] = 0;

        for (int i = 0; i < s.size(); i++) {

            p_hash[i + 1] = ((p_hash[i] * B) % M + s[i]) % M;

        }

    }


    long long get_hash(int start, int end) {

        long long raw_val =

            (p_hash[end + 1] - (p_hash[start] * pow[end - start + 1]));

        return (raw_val % M + M) % M;

    }

};

vector<long long> HashedString::pow = {1};

void solve(int num_tc)
{
    string s;
    cin >> s;
    int n = s.length();
    if(n == 1){
        cout << "NO" << endll;
        return;
    }
    HashedString hs(s);
    //first x: 0-x, last x = n-x, n
    //if n is even, n/2 is good so n/2 + 1
    //if n is odd, n/2 n/2 + 1 
    for(int x = n - 1; x >= 2 && x > n / 2; x--){
        //dbg(x);
        // dbg(s.substr(0, x));
        // dbg(hs.get_hash(0, x - 1));
        // dbg(s.substr(n - x, n - 1));
        // dbg(hs.get_hash(n - x, n - 1));
        if(hs.get_hash(0, x - 1) == hs.get_hash(n - x, n - 1)){
            cout << "YES" << endll;
            cout << s.substr(0, x) << endll;
            return;
        }
    }
    cout << "NO" << endll;
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
