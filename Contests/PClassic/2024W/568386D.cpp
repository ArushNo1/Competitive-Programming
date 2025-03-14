#include<bits/stdc++.h>
using namespace std;

void solve(int num_tc){
    int n;
    cin >> n;
    int N = n;
    vector<int> pfactors;
    for(int f = 2; f * f <= N; f++){
        if(N % f == 0){
            pfactors.push_back(f);
            while(N % f == 0){
                N /= f;
            }
        }
    }
    if(N > 1) pfactors.push_back(N);

    int ans = 0;
    for(int i = 1; i < n; i++){
        int count = 0;
        for(auto j : pfactors){
            if(i % j == 0){
                count++;
            }
            if(count > 1) break;
        }
        if(count == 1) ans++;
    }
    cout << ans << endl;
}

int main(){
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        solve(i + 1);    
    }
    return 0;
}