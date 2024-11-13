#pragma GCC Optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
#define endll '\n'

typedef long long ll;

using namespace std;

int main(){
    int r, c;
    cin >> r >> c;
    if(c < r){
        cout << -1 << endll;
        return 0;
    }
    //#
    vector<string> v(r, string(c, '.'));
    for(int row = 1; row < r; row++){ 
        v[row][row-1] = '#';
    }
    for(string s : v){
        cout << s << endll;
    }

}