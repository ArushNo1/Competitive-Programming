#pragma GCC optimize("Ofast")
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

typedef tree<int,null_type,less<int>,rb_tree_tag,
tree_order_statistics_node_update> indexed_set;


#define endll "\n"

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

#define tr(c,i) for(__typeof__((c)).begin() i = (c).begin(); i != (c).end(); i++)
#define present(c,x) ((c).find(x) != (c).end())

#define cpresent(c,x) (find(all(c),x) != (c).end())

#define sz(a) ll((a).size())
#define MOD ll(1e9+7)
#define INF ll(2e63-1)
#define dbg(x) cerr << __LINE__ << ": " << #x << "=" << x << endl;

void print(vii& arr){
	cerr << "{";
	for(auto const& n: arr){
		cerr << "[" << n.first << ", " << n.second << "], ";
	}
	cerr << "}" << endll;
}
inline void fillv(vi& v, int n) {
    for (int i = 0; i < n; ++i) {
        std::cin >> v[i];
    }
}

inline void open(const char * fin, const char * fout)
{
    freopen(fin, "r", stdin);
    freopen(fout, "w", stdout);
}

void solve()
{

}

int main()
{
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    ios_base::sync_with_stdio(0);
    
	
    open("pairup.in", "pairup.out");
    //int T = 1; cin >> T; for(int t = 0; t < T; t++) solve();
    int n;
    cin >> n;
    vector<pair<ll,ll>> counts(n);
    for(int i = 0; i < n ; i++){
        cin >> counts[i].second >> counts[i].first;
    }
    sort(all(counts));


    ll ans = 0;
    int left = 0, right = n - 1;
    while(left < right){
        ll pairs = min( counts[left].second, counts[right].second);
        counts[left].second -= pairs;
        counts[right].second -= pairs;
        ans = max(ans, counts[left].first + counts[right].first);
        if(counts[left].second == 0){
            left++;
        }
        if(counts[right].second == 0){
            right--;    
        }
    }
    if(counts[left].second > 0){
        ans = max(ans, counts[left].first * 2);
    }
    cout << ans << endll;
}