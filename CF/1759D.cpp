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

pll factor(ll n){
    pll result;
    while(n % 2 == 0){
        result.first++;
        n /= 2;
    }
    while(n % 5 == 0){
        result.second++;
        n /= 5;
    }
    return result;
}

ll pow10(pll a, pll b){
    return min(a.first + b.first, a.second + b.second);
}

void solve(int num_tc)
{
    ll n, m;
    cin >> n >> m;
    

    pll fact = factor(n);

    ll best = 0;

    for(int i = 1; i < 18; i++){
        ll twosneeded = i - fact.first;
        ll fivesneeded = i - fact.second;
        if(twosneeded <= 0 && fivesneeded <= 0){
            continue;
        }
        ll mink = 1;
        for(int j = 0; j < twosneeded; j++){
            mink *= 2;
        }
        for(int j = 0; j < fivesneeded; j++){
            mink *= 5;
        }
        if(mink > m){
            break;
        }
        ll k = (m / mink) * mink;
        best = n * k;
    }
    if(best == 0){
        cout << n * m << endll;
        return;
    }
    cout << best << endll;
   
    return;
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
