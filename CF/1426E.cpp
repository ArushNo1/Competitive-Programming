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


ll calc_score(vll& aorder, vll& border, vll amoves, vll bmoves){
    ll a = 0;
    ll b = 0;
    ll score = 0;
    auto eval = [](ll p1, ll p2){
        if(p1 == p2){
            return 0;
        }
        if(p1 == 0 && p2 == 1){
            return 1;
        }
        if(p1 == 1 && p2 == 2){
            return 1;
        }
        if(p1 == 2 && p2 == 0){
            return 1;
        }
        return 0;
    };

    
    while(a < 3 && b < 3){
        ll games = min(amoves[aorder[a]], bmoves[border[b]]);
        amoves[aorder[a]] -= games;
        bmoves[border[b]] -= games;
        score += games * eval(aorder[a], border[b]);
        if(amoves[aorder[a]] == 0){
            a++;
        }
        if(bmoves[border[b]] == 0){
            b++;
        }
    }
    return score;
}

void solve(int num_tc)
{
    ll n;
    cin >> n;
    vll a = {0, 1, 2};
    vll b = {0, 1, 2};
    vll amoves(3);
    vll bmoves(3);
    fillv(amoves, 3);
    fillv(bmoves, 3);

    //0 wins over 1
    sort(all(a));
    sort(all(b));
    ll max_score = 0;
    ll min_score = 2e9;
    do{
        do{
            ll score = calc_score(a, b, amoves, bmoves);
            max_score = max(max_score, score);
            min_score = min(min_score, score);
        }while(next_permutation(all(a)));
    }while(next_permutation(all(b)));
    cout << min_score << " " << max_score << endll;
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
