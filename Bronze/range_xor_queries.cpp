#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main()
{
    int n, q;
    cin >> n >>  q;
    int xors[n + 1];
    xors[0] = 0;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        xors[i + 1] = xors[i] ^ x;
    }
    for(int i = 0; i < q; i++){
        int a, b;
        cin >> a >> b;
        cout << ((xors[b]) ^ (xors[a - 1])) << endl;
    }
}
