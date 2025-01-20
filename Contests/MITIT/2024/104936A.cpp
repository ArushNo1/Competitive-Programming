#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef long long ll;
#define endll '\n'

#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << __LINE__ << ": " << #x << "=" << x << endll;

void solve(int num_tc)
{
    string s;
    cin >> s;
    int n = s.size();
    for(int len = 1; len * 2 < n; len++){
        if(s.substr(n - len, len) == s.substr(n - 2 * len, len)){
            cout << "YES" << endll;
            return;
        }
    }
    cout << "NO" << endll;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);  

    ll T = 1;
    cin >> T;
    for(ll t = 0; t < T; t++){
        solve(t+1);
    }
}
