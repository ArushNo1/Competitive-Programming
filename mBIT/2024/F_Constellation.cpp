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

void solve()
{

}

double dist(ii&a, ii&b){
    return sqrt(pow(a.first - b.first, 2) + pow(a.second - b.second, 2));
}
ii cp;
bool sorter(ii&a, ii&b){
    return dist(a, cp) < dist(b, cp);
}
double slope(ii&a, ii&b){
    return ((double) a.second - b.second)/(double)(a.first - b.first);
}

int main()
{
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    ios_base::sync_with_stdio(0);
    
    //int T = 1; cin >> T; for(int t = 0; t < T; t++) solve();
    vii points(7);
    for(int i = 0; i < 7; i++){
        cin >> points[i].first >> points[i].second;
    }

    double maxdist = -1;
    int max1, max2;
    for(int i = 0; i < 7; i++){
        for(int j = i + 1; j < 7; j++){
            double distance = dist(points[i], points[j]);
            if(distance > maxdist){
                maxdist = distance;
                max1 = i;
                max2 = j;
            }
        }
    }
    cp = points[max1];
    std::sort(all(points), sorter);
    
    // cerr << "maxpoint " << max1 << endll;
    // cerr << "point 1: " << points[1].first << ", " << points[1].second << endll;
    // double s1 = slope(cp, points[1]);
    // cerr << s1 << endll;
    // cerr << "point 2: " << points[2].first << ", " << points[2].second << endll;
    // double s2 = slope(cp, points[2]);
    // cerr << s2 << endll;
    // double s3 = s1 + 1.0/s2;
    // cerr << s3;
    if(abs(slope(cp, points[1])+1.0/slope(cp, points[2])) < 1e-5){
        cout << max1 + 1 << endll;
        return 0;
    }
    cout << max2 + 1 << endll;

    return 0;    
}
