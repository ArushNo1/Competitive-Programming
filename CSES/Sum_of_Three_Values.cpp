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

void print(vi& arr){
	cerr << "{";
	for(auto const& n: arr){
		cerr << n << ", ";
	}
	cerr << "}" << endll;
}
inline void fillv(vector<pair<ll,int>>& v, int n) {
    for (int i = 0; i < n; ++i) {
        std::cin >> v[i].first;
        v[i].second = i + 1;
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
    
	
	//open("abc.in", "abc.out");
    //int T = 1; cin >> T; for(int t = 0; t < T; t++) solve();
    int n, sum;
    cin >> n >> sum;
    vector<pair<ll,int>> arr(n);
    fillv(arr, n);
    sort(all(arr));

    if(arr[n - 1].first + arr[n - 2].first + arr[n - 3].first < sum){
        cout << "IMPOSSIBLE" << endll;
        return 0;
    }


    for(int f = 0; f < n; f++){
        ll tsum = sum - arr[f].first;
        if(tsum < arr[f].first){
            cout << "IMPOSSIBLE" << endll;
            return 0;
        }
        int l = f + 1;
        int r = n - 1;
        while(l < r){
            int lr = arr[l].first + arr[r].first;
            if(lr == tsum){
                cout << (arr[l].second) << " " << (arr[r].second) << " " << (arr[f].second) << endll;
                return 0;
            }
            else if(lr < tsum){
                l++;
            }
            else{
                r--;
            }
        }
    }
    cout << "IMPOSSIBLE" << endll;
}
