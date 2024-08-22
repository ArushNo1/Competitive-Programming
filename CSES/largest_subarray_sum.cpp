#include <bits/stdc++.h>
#include <limits.h>
using ll = long long;
 
 
using namespace std;
 
int main()
{
    //freopen("input.txt", "r", stdin);
    ll n;
    cin >> n;
    ll sums[n + 1];
    sums[0] = 0;
    for(ll i = 0; i < n; i++){
        cin >> sums[i + 1];
        sums[i + 1] += sums[i];
    }
 
    ll minn = LONG_LONG_MAX, max_dist = LONG_LONG_MIN, maxn = LONG_LONG_MIN;
    for(ll i = 0; i <= n; i++){
        ll c = sums[i], d = c - sums[i - 1];
        if(d < 0 && d > maxn){
            maxn = d;
        }
        if(c < minn){
            minn = c;
        }
        else if(c - minn > max_dist){
            max_dist = c - minn;
        }
    }
    if(max_dist == LONG_LONG_MIN) cout << maxn << endl;
    else cout << max_dist << endl;
}

