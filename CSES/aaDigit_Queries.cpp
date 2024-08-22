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
/*1234567891
  0111213141
  5161718192
  0212223242
  5262728293
  0313233343
  5363738394
  0414243444
  5464748495
  0515253545

  5565758596
  0616263646
  5666768697
  0717273747
  5767778798
  0818283848
  5868788899
  0919293949
  5969798991
  0010110210

  3104
*/
void solve()
{
    ll n;
    cin >> n;
    if(n < 10){
        cout << n << endll;
        return;
    }
    n-= 10;
    ll exp = 1;
    while(exp++ < 19){
        ll comp = (pow(10, exp) - pow(10, exp - 1)) * exp;
        // /(10^2 - 10^1) * 2
        if(n < comp){
            ll k = (n / exp) + pow(10, exp - 1); //which number to get
            cerr << "The number being retrd form is " << k << endll;
            //cerr << "tostring of tat " << to_string(k) << endll;
            cout << (to_string(k)[n % exp]) << endll;
            return;
        }
        n -= comp;
    }
}

int main()
{
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    ios_base::sync_with_stdio(0);
    
    int T = 1; cin >> T; for(int t = 0; t < T; t++) solve();
    
}
