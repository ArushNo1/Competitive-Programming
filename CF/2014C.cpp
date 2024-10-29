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
#define ans(x) cout << x << endll; return;

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

// File 1: /jit.cpp

#include <functional>
namespace searching{
    template<typename T>
    T firstTrue(T low, T high, std::function<bool(T)> f){
        while(low < high){
            T mid = low + (high - low) / 2;
            if(f(mid)){
                high = mid;
            }
            else{
                low = mid + 1;
            }
        }
        return low;
    }
    template<typename T>
    T lastTrue(T low, T high, std::function<bool(T)> f){
        while(low < high){
            T mid = low + (high - low + 1) / 2;
            if(f(mid)){
                low = mid;
            }
            else{
                high = mid - 1;
            }
        }
        return low;
    }
    template<typename T>
    T ternaryFirstTrue(T low, T high, std::function<bool(T, T)> f){
        //G1 problem file
        /*
        ll l = 1, r = 1000;
    while(r - l > 2){
        ll m1 = (2 * l + r) / 3, m2 = (2 * r + l) / 3;
        ll mm = m1 * m2;
        cout << "? " << m1 << " " << m2 << endl;
        ll t;
        cin >> t;
        if(t == mm){
            l = m2;
            //cout << "d > m2" << endl;
        }
        else if(t == mm + m1){
            l = m1;
            r = m2;
            //cout << "m1 < d2 <= m2" << endl;
        }
        else{
            r = m1;
            //cout << "d2 <= m1" << endl;
        }
    }
    if(r - l == 2){
        cout << "? 1 " << l + 1 << endl;
        int t;
        cin >> t;
        if(t != l + 1){
            r = l + 1;
        }
    }
    cout << "! " << r << endl;
        */
    }
};




void solve(int num_tc)
{
    ll n;
    cin >> n;
    double sum = 0;
    vector<ld> arr(n);
    for(int i = 0; i < n; i++){
        ld t;
        cin >> t;
        sum += t;
        arr[i] = t;
    }
    
    sort(all(arr));

    auto eval = [&](ld x){
        arr.back() += x;
        double navg = (sum + x) / (n);
        auto it = lower_bound(all(arr), navg);
        int index = it - arr.begin();
        arr.back() -= x;
        return index > (n / 2);
    };

    ll low = 0, high = 2e9;
    ll counter = 0;
    while(low < high && (++counter) < 50){
        ll mid = low + (high - low + 1) / 2;
        dbg(low);
        dbg(high);
        dbg(mid);
        dbg(eval(mid));
        if(eval(mid)){
            high = mid;
        }
        else{
            low = mid + 1;
        }
    }
    dbg("______________________")
    dbg(low);
    if(low >= 2e9){
        cout << -1 << endll;
    }
    else{
        cout << low << endll;
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
