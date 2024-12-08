#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops") 
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
typedef pair<ll, ll> pll;
typedef vector<bool> vb;

typedef tree<int,null_type,less<int>,rb_tree_tag,
tree_order_statistics_node_update> indexed_set;


#define endll '\n'

#define all(x) (x).begin(), (x).end()
#define MOD ll(1e9+7)
#define inf int(2e31-1)
#define INF ll(2e63-1)
#define EPS ld(1e-9)
#define dbg(x) cerr << __LINE__ << ": " << #x << "=" << x << endll;
#define print(x) cout << __LINE__ << ": " << #x << "=" << x << endll;
#define ans(x) cout << (x) << endll; return;

// File 1: /t/Templates/Debugging/vectordbg.cpp

template <typename T>
ostream& operator<<(ostream& os, const vector<T>& arr) {
    os << "[";
    for (size_t i = 0; i < arr.size(); ++i) {
        os << arr[i] << " ";
    }
    os << "]";
    return os;
}

template <typename T>
ostream& operator<<(ostream& os, const vector<vector<T>>& grid) {
    os << "[\n";
    for (const auto& row : grid) {
        os << "  " << row << "\n";
    }
    os << "]";
    return os;
}

template <typename T, typename U>
ostream& operator<< (ostream& os, const pair<T, U>& x){
    os << "(" << x.first << ", " << x.second << ")";
    return os;
}

template <typename T, typename U>
ostream& operator<< (ostream& os, const vector<pair<T, U>>& arr){
	os << "{\n";
    for(const pair<T,U>& x : arr){
		os << "    " << x << endll;
	}
	os << "}";
    return os;
}
inline void open(string name){
    freopen((name + ".in").c_str(), "r", stdin);
	freopen((name + ".out").c_str(), "w", stdout);
}

ll calc(vll nums, ll mask){
    ll total = nums[0];
    for(ll i = 1; i < nums.size(); i++){
        if(mask & (1 << (i - 1))){
            total += nums[i];
        }
        else{
            total *= nums[i];
        }
    }
    return total;
}

ll solve(ll target, vll nums)
{
    for(ll mask = 0; mask < (1 << ((nums.size() - 1))); mask++){
        ll x = calc(nums, mask);
        if(x == target){
            return target;
        }
    }
    return 0;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);  
    
    ll total = 0;
    string s;

    while(getline(cin, s)){
        ll first = 0;
        ll ind = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == ':'){
                ind = i + 1;
                break;
            }
            else{
                first *= 10LL;
                first += s[i] - '0';
            }
        }

        istringstream iss(s.substr(ind));
        vll nums;
        ll j;
        while(iss >> j){
            nums.push_back(j);
        }
        total += solve(first, nums);
    }
    cout << total << endll;
}
