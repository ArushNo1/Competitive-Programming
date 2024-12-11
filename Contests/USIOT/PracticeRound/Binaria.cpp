#pragma GCC Optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
#define endll '\n'

typedef long long ll;

using namespace std;

int log2(ll x){
    ll count=0;
    while(x>0){
        x/=2;
        count++;
    }
    
    return count;

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    ll sum = 0;

    for(int i = 0; i < n; i++){
        ll x;
        cin >> x;
        ll t = (1LL << (log2(x))) - 1;
        sum += t - x;
    }
    
    cout << sum << endll;
}