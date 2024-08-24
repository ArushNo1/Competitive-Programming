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

bool closetoint(ld x){
    return min(abs(x - floor(x)), abs(x - ceil(x))) <= EPS;
}

void solve(int num_tc)
{
    #pragma region //input loading
    int n;
    cin >> n;
    vector<ld> arr;
    map<int, ll> counts;
    ld sum = 0;
    for(int i = 0; i < n; i++){
        int t;
        cin >> t;
        arr.push_back(ld(t));
        sum += t;
        counts[t]++;
    }
    #pragma endregion

    ld requiredsumasdouble = sum * 2.0 / n;
    cerr << setprecision(20);
    if(!closetoint(requiredsumasdouble)){
        cout << 0 << endll;
        return;
    }
    int desiredsum = (int) (requiredsumasdouble + 0.5);
    ll total = 0;
    #pragma region //edgecase
    if(counts.size() == 1){
        int a = counts.begin()->first;
        dbg(a);
        if(abs(requiredsumasdouble/2.0 - a) <= EPS){
            ll c = counts.begin()->second;
            total += c * (c - 1) / 2;
        }
        cout << total << endll;
        return;
    }
    #pragma endregion

    auto l = counts.begin();
    auto r = counts.rbegin();
    auto a = l->first, b = r->first;
    while(a <= b){
        //dbg(a);
        //dbg(b);
        if(a + b == desiredsum){
            if(a == b){
                total += l->second * (l->second - 1) / 2;
                break;
            }
            total += (l->second * r->second);
            l++;
            r++;
        }
        else if(a + b > desiredsum){
            r++;
        }
        else{
            l++;
        }
        a = l->first;
        b = r->first;
    }
    cout << total << endll;
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
