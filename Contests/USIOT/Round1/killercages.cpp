#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef long long ll;
#define endll '\n'

#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << __LINE__ << ": " << #x << "=" << x << endll;
// File 1: /t/Math/IntegerSqrt.cpp
ll isqrt(ll n){
    ll low = 0, high = n;
    while(low < high){
        ll mid = low + (high - low + 1) / 2;
        ll mid2 = mid * mid;
        if(mid2 == n){
            return mid;
        }
        if(mid * mid <= n){
            low = mid;
        } else {
            high = mid - 1;
        }
    }
    return low;
}
void solve(int num_tc)
{

    ll n, k;
    cin >> n >> k;

    if(k == 1){
        cout << "YES" << endll;
        return;
    }
    if(n < k){
        cout << "NO" << endll;
        return;
    }
    int maxtadd = 0;

    for(int i = 1; i < k; i++){
        if(n < i){
            maxtadd = i - 1;
            break;
        }
        if(i == k - 1){
            n -= i;
            maxtadd = i;
            break;
        }
        n -= i;
    }


    if(n - maxtadd > 2){
        cout << "NO" << endll;
        return;
    }
    if(n <= maxtadd){
        cout << "NO" << endll;
        return;
    }


    

    cout << "YES" << endll;
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
