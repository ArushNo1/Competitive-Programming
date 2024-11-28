#include <bits/stdc++.h>
#include <cstdlib>
#include <unordered_map>
using namespace std;
int main(){

    int n;
    cin >> n;
    long long lawn[n];
    for(int i = 0; i < n; i++){
        cin >> lawn[i];
    }
    long long amt_to_add = 0;
    long long amt_to_add_to_add = 0;
    long long sprays = 0;
    for(int i = 0; i < n; i++){
        sprays += abs(lawn[i] - amt_to_add);
        amt_to_add_to_add += lawn[i];
        amt_to_add += amt_to_add_to_add;
    }
    cout << sprays;
}
