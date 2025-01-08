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

void solve(int num_tc)
{
    string s;
    cin >> s;
    int n = s.size();
    if(n == 1){
        cout << 0 << endll;
        return;
    }
    if(s[0] < '4' || ((s[0] == '4') && (s[1] < '4'))){
        ll sum = 0;
        ll pow10 = 1;
        for(ll i = n - 2; i > 0; i--){
            sum += i * pow10;
            pow10 *= 10;
        }
        cout << sum * 5 << endll;
        return;
    }
    if(s[0] >= '5'){
        ll sum = 0;
        ll pow10 = 1;
        for(ll i = n - 1; i > 0; i--){
            sum += i * pow10;
            pow10 *= 10;
        }
        cout << sum * 5 << endll;
        return;
    }
    if(s[0] == '4'){
        string t = "4";
        for(int i = 1; i < n; i++){
            t.push_back('4');
        }
        t.back() = '5';
        int a = stoi(s);
        int b = stoi(t);
        if(b > a){
            b = a + 1;
        }
        ll sum = 0;
        ll pow10 = 1;
        for(ll i = n - 2; i > 0; i--){
            sum += i * pow10;
            pow10 *= 10;
        }
        cout << sum * 5 + (a - b + 1)<< endll;
        return;
    }
    cout << 0 << endll;
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
