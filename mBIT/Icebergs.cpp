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

void solve()
{

}

int main()
{
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    ios_base::sync_with_stdio(0);
    
    //int T = 1; cin >> T; for(int t = 0; t < T; t++) solve();
    int n;
    cin >> n;
    double distances[n][n];
    vector<bool> sunk(n);
    vii positions(n);
    for(int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        positions[i] = make_pair(x, y);
        distances[i][i] = HUGE_VAL;
        for(int j = 0; j < i; j++){
            double dist = sqrt(pow(x - positions[j].first, 2) + pow(y - positions[j].second, 2));
            distances[i][j] = dist;
            distances[j][i] = dist;
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cerr << distances[i][j] << " ";
        }
        cerr << endll;
    }
    

    int left = n;
    int i = 0;
    while(left > 1){
        while(sunk[i]) i = (i + 1) % n;
        cerr << "choosing penguin: " << i << endll;
        int minind = 0;
        int j = 0;
        while(sunk[j]) j++;
        minind = j;
        dbg(minind);
        for(; j < n; j++){
            dbg(j);
            while(sunk[j]) j++;
            dbg(distances[i][j]);
            if(distances[i][j] < distances[i][minind]){
                minind = j;
            }
        }
        cerr << "it shoots : " << minind << endll;
        sunk[minind] = true;
        for(int a = 0; a < n; a++){
            cerr << sunk[a] << " ";
        }
        left--;
        i = (i + 1) % n;
    }
    cout << (i) << endll;

}
