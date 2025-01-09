#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops") 
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

typedef tree<int,null_type,less<int>,rb_tree_tag,
tree_order_statistics_node_update> indexed_set;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef long long ll;
typedef vector<ll> vll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef vector<bool> vb;

#define endll '\n'

#define all(x) (x).begin(), (x).end()
#define MOD ll(1e9+7)
#define inf int(1e9+1)
#define INF ll(1e18+1)
#define EPS ld(1e-9)

template <typename T>
inline void fillv(vector<T>& v, int n) {
    for (int i = 0; i < n; ++i) {
        std::cin >> v[i];
    }
}
template <typename T, typename U>
inline void fillv(vector<pair<T, U>>& v, int n, bool inv = false){
	if(inv){
		for(int i = 0 ; i < n; ++i){
			cin >> v[i].second >> v[i].first;
		}
		return;
	}
	for (int i = 0; i < n; ++i) {
        cin >> v[i].first >> v[i].second;
    }
	return;
}

inline void open(string name){
    freopen((name + ".in").c_str(), "r", stdin);
	freopen((name + ".out").c_str(), "w", stdout);
}

// File 1: /t/DSA/String_Hashing.cpp


class HashedString {
  private:
	// change M and B if you want
	static const long long M = 1e9 + 9;
	static const long long B = 9973;

	// pow[i] contains B^i % M
	static vector<long long> pow;

	// p_hash[i] is the hash of the first i characters of the given string
	vector<long long> p_hash;
	
  public:
	HashedString(const string &s) : p_hash(s.size() + 1) {
		while (pow.size() <= s.size()) { pow.push_back((pow.back() * B) % M); }
		p_hash[0] = 0;
		for (int i = 0; i < s.size(); i++) {
			p_hash[i + 1] = ((p_hash[i] * B) % M + s[i]) % M;
		}
	}

    // both ends are inclusive
	long long get_hash(int start, int end) {
		long long raw_val =
		    (p_hash[end + 1] - (p_hash[start] * pow[end - start + 1]));
		return (raw_val % M + M) % M;
	}
};

vector<long long> HashedString::pow = {1};


//comment to enable debugging
#define dbg(x)

#ifndef dbg
#define dbg(x) cerr << __LINE__ << ": " << #x << "=" << x << endl;
//edit for specific DS
#include <mapdbg.h>
#endif

bool toofar(pll s1, pll s2, string s){
    ll len = s1.second - s1.first + 1;
    bool can = true;
    for(int i = 0; i < len; i++){
        dbg(s1.first + i);
        dbg(s2.first + i);
        if(s[s1.first + i] != s[s2.first + i]){
            if(!can){
                return true;
            }
            can = false;
        }
        dbg(can);
    }
    return false;
}

void solve(int num_tc)
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    HashedString hs(s);
    for(int strlen = 1; strlen <= n; strlen++){
        if(n % strlen != 0){
            continue;
        }
        dbg(strlen);
        ll hash1 = -1;
        ll hash2 = -1;
        pll str1 = {-1, -1};
        pll str2 = {-1, -1};
        ll count1 = -1;
        ll count2 = -1;
        bool fail = false;
        for(int i = 0; i <= n - strlen; i+= strlen){
            dbg(i);
            dbg(hash1);
            dbg(hash2);
            dbg(count1);
            dbg(count2);
            if(count1 > 1 || count2 > 1){
                dbg(str1);
                dbg(str2);
            }
            ll hash = hs.get_hash(i, i + strlen - 1);
            if(hash == hash1){
                dbg("match1");
                count1++;
            }
            else if(hash == hash2){
                dbg("match2");
                count2++;
            }
            else if(hash1 == -1){
                dbg("set1");
                hash1 = hash;
                count1 = 1;
                str1 = {i, i + strlen - 1};
            }
            else if(hash2 == -1){
                dbg("set2");
                hash2 = hash;
                count2 = 1;
                str2 = {i, i + strlen - 1};
                dbg(str1);
                dbg(str2);
                if(toofar(str1, str2, s)){
                    dbg("mismatch");
                    fail = true;
                    break;
                }
            }
            else{
                dbg("third string");
                fail = true;
                break;
            }
            if(count1 > 1 && count2 > 1){
                dbg("too many 2");
                fail = true;
                break;
            }
        }
        if(!fail){
            cout << strlen << endll;
            return;
        }
    }
    cout << 0 << endll;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);  

    ll T = 1;
    cin >> T;
    for(ll t = 0; t < T; t++){
        solve(t+1);
    }
}
