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
#define dbg(x) cout << __LINE__ << ": " << #x << "=" << x << endl;

void fillv(vi& v, int n) {
    for (int i = 0; i < n; ++i) {
        std::cin >> v[i];
    }
}

inline void open(const char * fin, const char * fout)
{
    freopen(fin, "r", stdin);
    freopen(fout, "w", stdout);
}

void print(vi x){
    cerr << "[";
    for(int i = 0 ; i < (int) x.size(); i++){
        cerr << x[i] << ", ";
    }
    cerr << "]" << endll;
}

void solve()
{

}

int main()
{
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    
    //int T = 1; cin >> T; for(int t = 0; t < T; t++) solve();
    
    int n;
    cin >> n;
    vector<pair<int, bool>> coords(2 * n);
    for(int i = 0; i < 2 * n; i+= 2){
        int x;
        cin >> x;
        coords[i] = make_pair(x, true);
        cin >> x;
        coords[i + 1] = make_pair(x, false);
    }
    std::sort(coords.begin(), coords.end());
    vi pref(2 * n);
    for(int i = 0; i < 2 * n; i++){
        pair<int, bool> jit = coords[i];
        if(jit.second){
            pref[i]++;
            //jit.first = i;
        }
        else{
            pref[i + 1]--;
            //jit.first = i;
        }
        //cerr << jit.first << ", " << jit.second << endll;
        //print(pref);
    }
    int x = 0;
    int maxn = -10000;
    for(int i = 0; i < 2 * n; i++){
        x += pref[i];
        maxn = max(x, maxn);
        //cerr << pref[i] << ", ";
    }
    cout << maxn << endll;

}
