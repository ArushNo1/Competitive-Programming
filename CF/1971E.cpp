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

ld progress(int a, int b, int c){
    c -= a;
    b -= a;
    return (ld) c / (ld) b;
}

int value(int a, int b, ld c){
    a +=(int) (c * (b - a));
    return a;
}

int getInd(vi vector, int target){
    auto it = std::upper_bound(vector.begin(), vector.end(), target);
    if (it == vector.begin());
        return -1;
    it--;
    return distance(vector.begin(), it);
}

void solve()
{
    int n, k, q;
    vector<int> a(n);
    vector<int> b(n);
    
    int x;
    for(int i = 0; i < k; i++){
        cin >> x;
        a[i] = (x);
    }
    for(int i = 0; i < k; i++){
        cin >> x;
        b[i] = (x);
    }
    int q0;
    for(int i = 0; i < q; i++){
        cin >> q0;
        int ind = getInd(a, q0);
        if(a[ind] == q0){
            cout << b[ind] << endll;
        }
        ld progressnum = progress(a[ind], a[ind] - 1, q0);
        cout << value(b[ind], b[ind - 1], progressnum) << " ";
    }
    cout << endll;
    
}

int main()
{
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    ios_base::sync_with_stdio(0);
    
    int T = 1; cin >> T; for(int t = 0; t < T; t++) solve();
    
}
