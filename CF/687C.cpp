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

#define oreq(a, b) a = (a) || (b);

void solve(int num_tc)
{
    ll n, desiredsum;
    cin >> n >> desiredsum;
    vll coins(n);
    fillv(coins, n);
    sort(all(coins));

    vector<vector<vector<bool>>> dp(n + 1, vector<vector<bool>>(desiredsum + 1, vector<bool>(desiredsum + 1, false)));
    //dp[i][j][k] is if it's possible to use the first i coins, making sum j, with subset sum k
    dp[0][0][0] = true;
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= desiredsum; j++){
            for(int k = 0; k <= j; k++){
                //don't add the coin in
                oreq(dp[i + 1][j][k], dp[i][j][k]);

                if((j + coins[i]) <= desiredsum){
                    //add the coin in, with existing sums
                    oreq(dp[i + 1][j + coins[i]][k], dp[i][j][k]);
                    if((k + coins[i]) <= desiredsum){
                        //add the coin in, with extra sums
                        oreq(dp[i + 1][j + coins[i]][k + coins[i]], dp[i][j][k]);    
                    }
                }
            }
        }
    }
    

    vi result;
    for(int i = 0; i <= desiredsum; i++){
        if(dp[n][desiredsum][i]){
            result.push_back(i);
        }
    }
    cout << result.size() << endll;
    for(int i = 0; i < result.size(); i++){
        cout << result[i] << " ";
    }
    cout << endll;
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
