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

vector<char> s;

string next(int pos, int len){
    return string(s.data() + pos, len);
}

int main()
{
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    ios_base::sync_with_stdio(0);
    
    open("whereami.in", "whereami.out");

    //int T = 1; cin >> T; for(int t = 0; t < T; t++) solve();
    int n;
    cin >> n;
    s = vector<char>(n);
    int k = 1;
    unordered_set<char> chars;
    for(int i = 0; i < n; i++){
        cin >> s[i];
        if(k == 1 && chars.count(s[i]) != 0){
            k = 2;
        }
        chars.insert(s[i]);
    }
    if(k == 1){
        cout << 1 << endll;
        return 0;
    }
    unordered_set<string> subs;
    bool pass = false;
    for(; k <= n; k++){
        //cerr << k << " -- " << (n - k) <<  endll;
        pass = true;
        for(int i = 0; i <= n - k; i++){
            //cerr << i << " ";
            string str = next(i, k);
            //cerr << str << endll;
            if(subs.count(str) != 0){
                //cerr << "\tfound dupe of " << str << endll;
                pass = false;
                break;
            }
            subs.insert(str);
        }
        if(pass){
            break;
        }
        subs.clear();
    }
    cout << k << endll;
}
