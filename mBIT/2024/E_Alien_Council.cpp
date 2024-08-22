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

struct al{
    int e, l, a;

    bool operator==(al& other){
        return (this->e == other.e) && (this->l == other.l) && (this->a == other.a);
    }
};
bool fail = false;
al emax(const al& a, const al& b, const al&c){
    fail = false;
    if(b.e > a.e && b.e > c.e){
        return b;
    }
    if(c.e > b.e && c.e > a.e){
        return c;
    }
    if(a.e > b.e && a.e > c.e){
        return a;
    }
    fail = true;
    return a;
}
al lmax(const al& a, const al& b, const al&c){
    fail = false;
    if(b.l > a.l && b.l > c.l){
        return b;
    }
    if(c.l > b.l && c.l > a.l){
        return c;
    }
    if(a.l > b.l && a.l > c.l){
        return a;
    }
    fail = true;
    return a;
}
al amax(const al& a, const al& b, const al&c){
    fail = false;
    if(b.a > a.a && b.a > c.a){
        return b;
    }
    if(c.a > b.a && c.a > a.a){
        return c;
    }
    if(a.a > b.a && a.a > c.a){
        return a;
    }
    fail = true;
    return a;
}
void print(al x){
    //cerr << "e" << x.e << " l" << x.l << " a" << x.a << endll;
}

void print(vector<al> v){
    for(al x : v){
        //print(x);
    }
}

int main()
{
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    ios_base::sync_with_stdio(0);
    
    //int T = 1; cin >> T; for(int t = 0; t < T; t++) solve();
    int n;
    cin >> n;
    vector<al> orgs, borgs, chorgs;
    string s;
    for(int i = 0; i < n; i++){
        al input;
        cin >> input.e >> input.l >> input.a;
        cin >> s;
        if(s[0] == 'C'){
            chorgs.push_back(input);
        }
        else if(s[0] == 'B'){
            borgs.push_back(input);
        }
        else{
            orgs.push_back(input);
        }
    }
    int counter = 0;
    for(int o = 0; o < (int) orgs.size(); o++){
        for(int c = 0; c < (int) chorgs.size(); c++){
            for(int b = 0; b < (int) borgs.size(); b++){
                //cerr << "The triple is " << endll;
                //print(orgs[o]);
                //print(chorgs[c]);
                //print(borgs[b]);
                al e = emax(orgs[o], chorgs[c], borgs[b]);
                //cerr << !fail << " emax ";
                //print(e);
                if(fail) continue;
                al l = lmax(orgs[o], chorgs[c], borgs[b]);
                //cerr << !fail << " lmax ";
                //print(l);
                if(fail || l == e) continue;
                al a = amax(orgs[o], chorgs[c], borgs[b]);
                //cerr << !fail << " amax ";
                //print(a);
                if(fail || a == l || a == e) continue;
                counter++;
                //cerr << "success" << endll;
            }
        }
    }
    cout << counter << endll;
}
