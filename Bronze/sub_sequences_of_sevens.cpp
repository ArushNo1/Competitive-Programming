#include <bits/stdc++.h>
using namespace std;
using l = long long;

int main(){
    freopen("div7.in", "r", stdin);
    freopen("div7.out", "w", stdout);
    l n;
    cin >> n;

    l cows, sums[n + 1];
    sums[0] = 0;
    for(int i = 0; i < n; i++){
        cin >> cows;
        sums[i + 1] = (sums[i] + cows) % 7;
    }
    vector<l> first(7), last(7);
    for(int i = 1; i <= n; i++){
        last[sums[i]] = i;
    }
    for(int i = n; i > 0; i--){
        first[sums[i]] = i;
    }
    l min_diff = 0;
    for(int i = 0; i < 7; i++){
        min_diff = max(min_diff, last[i] - first[i]);
    }
    cout << min_diff << endl;

}
