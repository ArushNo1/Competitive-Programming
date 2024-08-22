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
int n;
ii match(vector<bool>&a, vector<bool>&b, vector<bool>&c){
    int max_length = 0, index = -1;
    int run = 0, ind = -1;
    for(int i = 0; i < n; i++){
        c[i] = a[i] != b[i];
        if(c[i]){
            if(run == 0) ind = i;
            run++;
        }
        else{
            if(run > max_length){
                max_length = run;
                index = ind;
            }
            run = 0;
            ind = -1;
        }
    }
    return {max_length, index};
}

int main()
{
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    ios_base::sync_with_stdio(0);
    
    open("breedflip.in", "breedflip.out");
    //int T = 1; cin >> T; for(int t = 0; t < T; t++) solve();
    cin >> n;
    vector<bool> cows(n), expected(n), diff(n);
    for(int i = 0; i < n; i++){
        char c;
        cin >> c;
        expected[i] = (c == 'G');
    }
    for(int i = 0; i < n; i++){
        char c;
        cin >> c;
        cows[i] = (c == 'G');
    }
    int count = 0;
    ii result = match(expected, cows, diff);
    while(result.second != -1){
        //cerr << "len: " << result.first << ", ind = " << result.second << endll;
        count++;
        for(int i = result.second; i < result.first + result.second; i++){
            cows[i] = !cows[i];
        }
        result = match(expected, cows, diff);
    }
    cout << count << endll;
}
