#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops") 
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

typedef tree<int,null_type,less<int>,rb_tree_tag,
tree_order_statistics_node_update> indexed_set;

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
#define maxeq(a, b) a = max<decltype(a)>(a, b)
#define mineq(a, b) a = min<decltype(a)>(a, b)

#define MOD ll(1e9+7)
#define inf int(1e9+1)
#define INF ll(1e18+1)
#define EPS ld(1e-9)

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
T last_true(T lo, T hi, std::function<bool(T)> f) {
    lo--;
    while (lo < hi) {
        T mid = lo + (hi - lo + 1) / 2;
        if (f(mid)) {
            lo = mid;
        } else {
            hi = mid - 1;
        }
    }
    return lo;
}

template<typename T>
T first_true(T lo, T hi, std::function<bool(T)> f) {
	hi++;
	while (lo < hi) {
		T mid = lo + (hi - lo) / 2;
		if (f(mid)) {
			hi = mid;
		} else {
			lo = mid + 1;
		}
	}
	return lo;
}

struct soapystack{
    vvi plates;
    int startindex = 0;
    soapystack(){};
    void addplate(int plate){
        if(plates.size() == 0){
            plates.push_back({plate});
            return;
        }
        if(plates.back().back() < plate){
            plates.push_back({plate});
            return;
        }
        int it = first_true<int>(0, plates.size() - 1, [&](int q){
            return plates[q].back() > plate;
        });
        plates[it].push_back(plate);
    }
    int removeplates(int d, vi& clean){
        for(int i = startindex; i < plates.size(); i++){
            for(int j = plates[i].size() - 1; j >= 0; j--){
                if(plates[i][j] != clean[d]){
                    return d;
                }
                d++;
                plates[i].pop_back();
            }
            startindex++;
        }
        return d;
    }
    friend ostream& operator<< (ostream& os, const soapystack& s){
        os << "{\n";
        for(int i = s.startindex; i < s.plates.size(); i++){
            os << "    ";
            for(int j = 0; j < s.plates[i].size(); j++){
                os << s.plates[i][j] << " ";
            }
            os << endll;
        }
        return os << "}";
    }
};

//comment to enable debugging
#define dbg(x)

#ifndef dbg
#define dbg(x) cerr << __LINE__ << ": " << #x << "=" << x << endl;
//edit for specific DS
#include <alldebug.h>
#endif

void solve(int num_tc)
{
    int n;
    cin >> n;
    vi allplates(n);
    fillv(allplates, n);

    cout << last_true<int>(1, n, [&](int dishes){
        dbg(dishes);
        vi dirty(allplates.begin(), allplates.begin() + dishes);
        vi clean(all(dirty));
        sort(all(clean));
        dbg(dirty);
        dbg(clean);
        int d = 0;
        soapystack soapy;
        for(int i = 0; i < dishes; i++){
            dbg(i);
            dbg(dirty[i]);
            if(dirty[i] == clean[d]){
                d++;
                d = soapy.removeplates(d, clean);
            }
            else{
                soapy.addplate(dirty[i]);
            }
            dbg(soapy);

            if(d == dishes){
                return true;
            }
        }
        dbg(soapy);
        dbg(d);
        d = soapy.removeplates(d, clean);
        dbg("true");
        return d == dishes;
    }) << endll;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);  

    open("dishes");
    ll T = 1;
    //cin >> T;
    for(ll t = 0; t < T; t++){
        solve(t+1);
    }
}
