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

int H = 0, P = 1, S = 2;
inline int result(int a, int b){
    if(a == b) return 0;
    if(b == H && a == P) return 1;
    if(b == P && a == S) return 1;
    if(b == S && a == H) return 1;
    return 0;
}

#define maxeq(a, b) a = max(a, b)
void solve(int num_tc)
{
    int n, k;
    cin >> n >> k;
    vi moves(n);
    for(int i = 0; i < n; i++){
        char c;
        cin >> c;
        switch(c){
            case 'H': moves[i] = H; break;
            case 'P': moves[i] = P; break;
            case 'S': moves[i] = S; break;
        }
    }

    vector<vvi> dp(n+1, vvi(k+1, vi(3, 0)));
    //dp[i][j][k]: i games played, j switches, k move

    for(int i = 0; i < n; i++){
        int move_fj = moves[i];
        for(int j = 0; j <= k; j++){
            for(int l = 0; l < 3; l++){
                maxeq(dp[i+1][j][l], dp[i][j][l] + result(move_fj, l));
                if (j < k) {
                    for (int next_move = 0; next_move < 3; next_move++) {
                        if (next_move != l) {
                            maxeq(dp[i+1][j+1][next_move], dp[i][j][l] + result(move_fj, next_move));
                        }
                    }
                }
            }
        }
    }
    int maxval = 0;
    for (int j = 0; j <= k; j++) {
        for (int l = 0; l < 3; l++) {
            maxeq(maxval, dp[n][j][l]);
        }
    }
    cout << maxval << endll;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);  

    open("hps");
    ll T = 1;
    //cin >> T;
    for(ll t = 0; t < T; t++){
        solve(t+1);
    }
}
