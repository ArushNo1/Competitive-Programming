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

ll msb(ll x){
    if(x == 0) return 0;
    return 63 - __builtin_clzll(x);
}

void solve(int num_tc)
{
    ll lowbound, highbound;
    cin >> lowbound >> highbound;
    if((highbound - lowbound) == 2){
        cout << lowbound << " " << lowbound+1 << " " << highbound << endll;
        return;
    }
    bitset<30> l (lowbound);
    bitset<30> r (highbound);
    bitset<30> m (0);
    bool gl = false;
    bool lr = false;
    for(int i = 29; i >= 0; i--){
        if(l[i] && r[i]){
            if(gl){
                m[i] = 0;
                lr = true;
                continue;
            }
            else{
                m[i] = 1;
                continue;
            }
        }
        if(!l[i] && !r[i]){
            if(lr){
                m[i] = 1;
                gl = true;
                continue;
            }
            else{
                m[i] = 0;
                continue;
            }
        }
        if(gl){
            m[i] = 0;
            lr = true;
            continue;
        }
        if(lr){
            m[i] = 1;
            gl = true;
            continue;
        }
        m[i] = 0;
        if(r[i]){
            lr = true;
        }
    }

    cout << l.to_ullong() << " " << m.to_ullong() << " " << r.to_ullong() << endll;
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
