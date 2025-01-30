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

//comment to enable debugging
#define dbg(x)

#ifndef dbg
#define dbg(x) cerr << __LINE__ << ": " << #x << "=" << x << endl;
//edit for specific DS
#include <alldebug.h>
#endif

void solve(int num_tc)
{
    int n, k;
    cin >> n >> k;
    vector<int> ans;
    //ans represents the sequence so far
    //sum is the sum of the sequence (aka one less than the first unreachable number)
    
    //add powers of 2 while the sum remains less than k
    int sum = 0;
    while((2 * sum + 1) < k){
        ans.push_back(sum + 1);
        sum += sum + 1;
    }

    //add in the missing value so that sums from 0 to k - 1 are possible
    int j = k - sum - 1;
    if(j != 0){
        ans.push_back(k - sum - 1);
        sum += k - sum - 1;
    }
    
    //start the sequence following after k
    ans.push_back(k + 1);
    sum += k + 1;
    if(sum >= n){
        cout << ans.size() << endll;
        for(int i = 0; i < ans.size(); i++){
            cout << ans[i] << " ";
        }
        cout << endll;
        return;
    }
    ans.push_back(sum + 1);
    
    //next represents the next "hole" in the sequence
    int next = sum + k + 1;
    sum += sum + 1; // the hole should be calculated with the old sum, not the new one (line 99)
    while(sum < n){
        ans.push_back(next);
        sum += next;
        next *= 2;
    }
    //The observation is that the hole jumps to 2 times the previous hole

    //add 1 extra value in case the sum is still less than n
    if(next <= n){
        ans.push_back(next);
    }
    
    //output the answer
    cout << ans.size() << endll;
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }
    cout << endll;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);  

    ll T = 1;
    cin >> T;
    for(ll t = 0; t < T; t++){
        solve(t+1);
    }
}
