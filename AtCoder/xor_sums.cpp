#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<long long> xors(n + 1);
    for(int i = 0; i < n; i++){
        cin >> xors[i + 1];
        xors[i + 1] ^= xors[i];
    }

    long long total = 0;

    for(int l = 1; l <= n; l++){
        for(int r = l; r <= n; r++){
            total += (((xors[r] ^ xors[l - 1]) * (r - l + 1)));
        }
        total %= 998244353;
    }

    cout << (total % 998244353) << endl;
}
