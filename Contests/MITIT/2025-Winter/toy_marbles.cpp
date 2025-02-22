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

//comment to enable debugging
//!#define dbg(x)

#ifndef dbg
#define dbg(x) cerr << __LINE__ << ": " << #x << "=" << x << endl;
//edit for specific DS
#include <alldebug.h>
#endif

void solve(int num_tc)
{
    int n;
    cin >> n;
    vi c(n);
    for(int i = 0; i < n; i++){
        cin >> c[i];
        c[i]--;
    }

    vector<array<int, 3>> moves;

    for(int i = 0; i < n; i++){
        dbg(i);
        dbg(c);
        if(c[i] == i){
            continue;
        }
        while(c[i] != i){
            int otherside = c[c[i]];
            dbg(otherside);
            if(otherside == -1){
                moves.push_back({2, i, otherside});
                swap(c[i], c[c[i]]);
                break;
            }
            else if(otherside == c[i]){
                moves.push_back({2, i, c[i]});
                c[i] = -1;
                break;
            } else{
                moves.push_back({1, i, c[i]});
                swap(c[i], c[c[i]]);
            }
            dbg(c);
        }
    }
    cout << moves.size() << endll;
    for(auto move : moves){
        cout << move[0] << " " << move[1] + 1 << " " << move[2] + 1 << endll;
    }


}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);  

    ll T = 1;
    //cin >> T;
    for(ll t = 0; t < T; t++){
        solve(t+1);
    }
}
/*

int n;
    cin >> n;
    vi c(n);
    vi ind(n);

    for(int i = 0; i < n; i++){
        cin >> c[i];
        c[i]--;
        ind[c[i]] = i;
    }

    vi dc = c;
    sort(all(dc));

    vector<ii> moves;
    for(int i = 0; i < n; i++){
        if(dc[i] != c[i]){
            moves.push_back({i + 1, ind[dc[i]] + 1});
            swap(c[i], c[ind[dc[i]]]);
            swap(ind[c[i]], ind[c[ind[dc[i]]]]);
        }
    }
    cout << moves.size() << endll;
    for(ii p : moves){
        cout << "1 " << p.first << " " << p.second << endll;
    }
*/
