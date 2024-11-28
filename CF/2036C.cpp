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
#define dbg(x) cerr << __LINE__ << ": " << #x << "=" << x << endll;

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

// File 1: /t/Templates/Debugging/setdbg.cpp

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
    string s;
    cin >> s;
    int q;
    cin >> q;
    int n = s.size();
    set<int> locs;
    for(int i = 0; i < n - 3; i++){
        if(s[i] == '1' && s[i + 1] == '1' && s[i + 2] == '0' && s[i + 3] == '0'){
            locs.insert(i);
        }
    }
    for(int i = 0; i < q; i++){
        int j;
        char v;
        cin >> j >> v;
        j--;
        if(n < 4){
            cout << "NO" << endll;
            continue;
        }
        if(s[j] == v){
            cout << (locs.empty()? "NO" : "YES") << endll;
            continue;
        }
        s[j] = v;
        locs.erase(j - 3);
        locs.erase(j - 2);
        locs.erase(j - 1);
        locs.erase(j);
        if(s[j - 3] == '1' && s[j - 2] == '1' && s[j - 1] == '0' && s[j] == '0'){
            locs.insert(j - 3);
        }
        if(s[j - 2] == '1' && s[j - 1] == '1' && s[j] == '0' && s[j + 1] == '0'){
            locs.insert(j - 2);
        }
        if(s[j - 1] == '1' && s[j] == '1' && s[j + 1] == '0' && s[j + 2] == '0'){
            locs.insert(j - 1);
        }
        if(s[j] == '1' && s[j + 1] == '1' && s[j + 2] == '0' && s[j + 3] == '0'){
            locs.insert(j);
        }
        cout << (locs.empty()? "NO" : "YES") << endll;
    }

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
