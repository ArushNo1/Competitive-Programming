#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define dbg(x, y) debug(x, y, #x)

void debug(int n[], int len, string name){
    cout << "Array : " << name << endl;
    for(int i = 0; i < len; i++){
        cout << n[i] << ", ";
    }
    cout << endl;
}

int gcf(int a, int b){
    for(int i = min(a, b); i > 1; i--){
        if(a % i == 0 && b % i == 0){
            return i;
        }
    }
    return 1;
}

int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    int rgcf[n];
    int lgcf[n];
    int list[n];

    cin >> list[0];
    lgcf[0] = list[0];
    for(int i = 1; i < n; i++){
        cin >> list[i];
        lgcf[i] = gcf(lgcf[i - 1], list[i]);
    }
    rgcf[n - 1] = list[n - 1];
    for(int i = n - 2; i >= 0; i--){
        rgcf[i] = gcf(rgcf[i + 1], list[i]);
    }
    //dbg(list, n);
    //dbg(lgcf, n);
    //dbg(rgcf, n);
    int factors[n];
    int largest_factor = rgcf[1];

    for(int i = 1; i < n - 1; i++){
        factors[i] = gcf(rgcf[i + 1], lgcf[i - 1]);
        largest_factor = max(largest_factor, factors[i]);
    }
    //dbg(factors, n);
    
    largest_factor = max(largest_factor, lgcf[n - 2]);

    cout << largest_factor << endl;
}
