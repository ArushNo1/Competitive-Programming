#pragma GCC Optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
#define endll '\n'

#define rall(x) x.rbegin(), x.rend()

typedef long long ll;

using namespace std;

template <typename T>
ostream& operator<< (ostream& os, const vector<T>& arr){
	os << "[";
    for(const T x : arr){
		os << x << " ";
	}
	os << "]";
    return os;
}

void solve(){
    int n;
    cin >> n;
    string s; cin >> s;
    vector<int> consec{};
    int cur = 0;
    for(int i = 0; i < n; i++)
    {
        if(s[i] == '.')
        {
            cur++;
        }
        else 
        {   
            if(cur != 0) consec.push_back(cur);
            cur = 0;
        }
    }
    if(cur != 0) consec.push_back(cur);
    sort(rall(consec));

    ll ans = 0;
    for(ll time = 0; time < consec.size(); time++)
    {
        ans = max(ans, time + consec[time]/2 + 1);
    }

    cout << consec.size() << " " << ans << endll;
}

int main(){
    int T; cin >> T;

    for(int t = 0; t < T; t++)
    {
        solve();
    }
}