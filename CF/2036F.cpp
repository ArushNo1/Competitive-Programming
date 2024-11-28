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
// File 1: /t/Math/Range_XOR.cpp

long long xor1n(long long n){
    long long mod = n % 4;
    if(mod == 0){
        return n;
    }
    if(mod == 1){
        return 1;
    }
    if(mod == 2){
        return n + 1;
    }
    return 0;
}

long long xorlr(long long l, long long r){
    return xor1n(l - 1) ^ xor1n(r);
}

long long xorlr2(long long l, long long r){
    ll result = 0;
    for(ll i = l; i <= r; i++){
        result ^= i;
    }
    return result;
}
void solve(int num_tc)
{
    ll l, r, i, k;
    cin >> l >> r >> i >> k;
    ll unintersting = xorlr(l, r);
    //dbg(bitset<8>(l));
    //dbg(bitset<8>(r));
    //dbg(unintersting);
    //dbg(xorlr2(l, r));
    ll mask = (1 << (i)) - 1;
    //dbg(mask);
    ll low = l >> i;
    if((l & mask) > k) low++;
    //dbg(bitset<8>(low));
    ll high = r >> i;
    //dbg(bitset<8>(r & mask));
    if((r & mask) < k) high--;
    //dbg(bitset<8>(high));

    ll interesting = xorlr(low, high) << i;
    ll numinteresting = (high - low + 1);
    if(numinteresting % 2 == 1){
        interesting |= k;
    }

    cout << (interesting ^ unintersting) << endll;
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
