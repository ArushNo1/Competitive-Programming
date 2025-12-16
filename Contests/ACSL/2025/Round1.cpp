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


ostream& operator<< (ostream& os, const array<int, 3>& arr){
    os << "[";
    for(int i = 0; i < 3; i++){
        os << arr[i] << " ";
    }
    os << "]";
    return os;
}

//uncomment to disable debugging
#define dbg(x)
#ifndef dbg
#define dbg(x) cerr << __LINE__ << ": " << #x << "=" << x << endl;
#include <alldebug.h>
#endif



map<string, int> ringscores = {
    {"A", 1},
    {"R", 1},
    {"O", 3},
    {"G", 3},
    {"B", 6},
    {"AO", 5},
    {"OA", 5},
    {"BO", 10},
    {"OB", 10},
    {"BG", 10},
    {"GB", 10},
    {"RG", 5},
    {"GR", 5},
};
ii score(string toss){
    istringstream iss(toss);
    string t;
    int total = 0;
    int counter = 0;
    while(iss >> t){
        counter++;
        if(t.back() == '+'){
            t.pop_back();
            total += ringscores[t] + 2;
        }
        else{
            total += ringscores[t];
        }
    }
    return {total, counter};
}
string scoreTosses(int numPlayers, vector<string> tosses) {
    vector<array<int, 3>> scores(numPlayers);
    dbg(scores[0]);
    for(int i = 0; i < numPlayers; i++){
        scores[i][0] = i + 1;
        ii res = score(tosses[i]);
        scores[i][1] = res.first;
        scores[i][2] = res.second;
    }
    sort(all(scores), [](array<int, 3> a, array<int, 3> b){
        if(a[1] != b[1]){
            return a[1] > b[1];
        }
        if(a[2] != b[2]){
            return a[2] < b[2];
        }
        return a[0] < b[0];
    });
    dbg(scores);
    string output = "";
    for(int i = 0; i < scores.size(); i++){
        output += to_string(scores[i][0]);
        output += "-";
        output += to_string(scores[i][1]);
        output += " ";
    }
    return output;
}

void solve(int num_tc)
{
    int n;
    cin >> n;
    string q;
    getline(cin, q);
    getline(cin, q);
    vector<string> tosses(n);
    for(int i = 0; i < n; i++){
        string s;
        getline(cin, s);
        tosses[i] = s;
        dbg(s);
    }
    cout << scoreTosses(n, tosses) << endll;
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
